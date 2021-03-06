////////////////////////////////////////////////////////////////////////////////
// $Id$
// Author: juergen.mellinger@uni-tuebingen.de
// Description: Declarations for stream symbols related to error/info messages.
//              To report an error, write e.g.
//               bcierr << "My error message" << endl;
//              For an informational message, write
//               bciout << "My info message" << endl;
//
// $BEGIN_BCI2000_LICENSE$
//
// This file is part of BCI2000, a platform for real-time bio-signal research.
// [ Copyright (C) 2000-2012: BCI2000 team and many external contributors ]
//
// BCI2000 is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// BCI2000 is distributed in the hope that it will be useful, but
//                         WITHOUT ANY WARRANTY
// - without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.
//
// $END_BCI2000_LICENSE$
////////////////////////////////////////////////////////////////////////////////
#include "PCHIncludes.h"
#pragma hdrstop

#include "BCIStream.h"
#include "ThreadUtils.h"
#include "ParamList.h"
#include "ParamRef.h"
#include "RedirectIO.h"
#include <set>
#include <ctime>

using namespace std;
using namespace BCIStream;

namespace BCIStream {

class MessageDispatcher : public Dispatcher
{
  static const int cMaxTimeDiff = 1; // s

 public:
  MessageDispatcher();
  ~MessageDispatcher();

 protected:
  void OnCompress( BCIStream::Action, const string& );
  void OnCheck();
  int OnExecute();

 private:
  void ReportRepetitions();

  static set<MessageDispatcher*>& Instances();
  static LockableObject& GlobalMutex();

  int mCount;
  time_t mLastTime;
  BCIStream::Action mPrevAction;
  string mPrevMessage;
};

} // namespace

// Make sure ios_base is properly initialized before our OutStreams are
// constructed.
static ios_base::Init ios_base_Init_;

// Definitions of the actual global objects.
OutStream bcierr___( &RuntimeError );
OutStream bciwarn___( &Warning );
OutStream bciout___( &PlainMessage, 0 );
OutStream bcidbg___( &DebugMessage, 0 );

list<string> OutStream::sContext;

static struct Init { Init(); } init;
Init::Init()
{
  Tiny::Redirect( cerr, bcierr___ );
  Tiny::Redirect( cout, bciout___ );
  Tiny::Redirect( clog, bcidbg___ );
}

void
BCIStream::Apply( const ParamList& p )
{
  if( p.Exists( "Verbosity" ) )
  {
    int v = p( "Verbosity" );
    bciout.SetVerbosity( v );
    bciwarn.SetVerbosity( v );
  }
  if( p.Exists( "DebugLevel" ) )
    bcidbg.SetVerbosity( p( "DebugLevel" ) );
}

// OutStream
OutStream::OutStream( Action f, int level )
: std::ostream( 0 ),
  mVerbosityLevel( level ),
  mVerbosityLocked( false ),
  mpDispatcher( 0 )
{
  this->init( &mBuf );
  SetAction( f );
}

OutStream::~OutStream()
{
  mBuf.SetDispatcher( 0 );
  delete mpDispatcher;
}

void
OutStream::SetAction( Action inAction )
{
  if( mpDispatcher && mpDispatcher->Action() != inAction )
  {
    mBuf.SetDispatcher( 0 );
    delete mpDispatcher;
    mpDispatcher = 0;
  }
  if( mpDispatcher )
  {
    mpDispatcher->Idle();
  }
  else
  {
    mpDispatcher = CompressMessages() ? new MessageDispatcher : new Dispatcher;
    mpDispatcher->SetAction( inAction );
    mBuf.SetDispatcher( mpDispatcher );
  }
}

OutStream&
OutStream::operator()()
{
  mBuf.SetContext( sContext );
  return ResetFormat();
}

OutStream&
OutStream::operator()( const string& inContext )
{
  if( !ThreadUtils::InMainThread() || sContext.empty() )
    mBuf.SetContext( inContext );
  else
    mBuf.SetContext( sContext );
  return ResetFormat();
}

OutStream&
OutStream::ResetFormat()
{
  static ostringstream defaultFormat;
  this->copyfmt( defaultFormat );
  mVerbosityLocked = false;
  return *this;
}

OutStream&
OutStream::MessageVerbosity( int inLevel )
{
  if( !mVerbosityLocked )
  {
    if( mVerbosityLevel >= inLevel )
      rdbuf( &mBuf );
    else
      rdbuf( NULL );
    mVerbosityLocked |= ( inLevel == AlwaysDisplayMessage );
    mVerbosityLocked |= ( inLevel == NeverDisplayMessage );
  }
  return *this;
}

void
OutStream::SetContext( const std::string& s )
{
  if( s.empty() )
  {
    if( !OutStream::sContext.empty() )
      OutStream::sContext.pop_back();
  }
  else
    OutStream::sContext.push_back( s );
}

// OutStream::StringBuf
OutStream::StringBuf::StringBuf()
: std::stringbuf( std::ios_base::out ),
  mpDispatcher( 0 ),
  mNumFlushes( 0 )
{
}

void
OutStream::StringBuf::SetContext( const list<string>& s )
{
  mContext.clear();
  if( !s.empty() )
    for( list<string>::const_iterator i = s.begin(); i != s.end(); ++i )
      mContext += *i + ": ";
}

void
OutStream::StringBuf::SetContext( const std::string& s )
{
  if( s.empty() )
    mContext.clear();
  else
    mContext = s + ": ";
}

void
OutStream::StringBuf::SetDispatcher( Dispatcher* inpDispatcher )
{
  bool previous = mpDispatcher,
       empty = str().empty();
  if( previous && !empty )
    Flush();
  mpDispatcher = inpDispatcher;
  if( !previous && !empty )
    Flush();
}

void
OutStream::StringBuf::Flush()
{
  ++mNumFlushes;

  string s = str();
  str( "" );

  if( s.empty() || s == "\n" )
    s = "<empty message>";
  else for( size_t pos = s.find( '\0' ); pos != string::npos; pos = s.find( '\0', pos ) )
    s = s.substr( 0, pos ) + s.substr( pos + 1 );

  if( mpDispatcher )
    mpDispatcher->Dispatch( mContext, s );
}

int
OutStream::StringBuf::sync()
{
  if( pptr() == pbase() )
    return 0;

  int r = stringbuf::sync();
  Flush();
  return r;
}

// Dispatcher
void
Dispatcher::Dispatch( const string& inContext, const string& inMessage )
{
  BCIStream::Action action = mAction;
  string message = inMessage;
  OnFilter( action, message );
  OnCompress( action, inContext + message );
}

void
Dispatcher::OnFilter( BCIStream::Action& ioAction, string& ioMessage )
{
  if( !ioMessage.empty() && *ioMessage.rbegin() == '\n' )
    ioMessage.erase( ioMessage.length() - 1 );
  if( !ioMessage.empty() && !::ispunct( *ioMessage.rbegin() ) )
    ioMessage += '.';

  if( ioAction == &Warning || ioAction == &PlainMessage )
  {
    static const string warning = "warning";
    if( !::stricmp( ioMessage.substr( 0, warning.length() ).c_str(), warning.c_str() ) )
    {
      size_t pos = warning.length();
      while( pos < ioMessage.length() && ( ::ispunct( ioMessage[pos] ) || ::isspace( ioMessage[pos] ) ) )
        ++pos;
      ioMessage = ioMessage.substr( pos );
      ioAction = &Warning;
    }
  }
}

// MessageDispatcher
MessageDispatcher::MessageDispatcher()
: mPrevAction( LogicError ),
  mLastTime( ::time( 0 ) ),
  mCount( 0 )
{
  Lock _( GlobalMutex() );
  Instances().insert( this );
}

MessageDispatcher::~MessageDispatcher()
{
  ReportRepetitions();
  Lock _( GlobalMutex() );
  Instances().erase( this );
}

void
MessageDispatcher::OnCompress( BCIStream::Action inAction, const string& inMessage )
{
  {
    Lock _( GlobalMutex() );
    for( set<MessageDispatcher*>::const_iterator i = Instances().begin(); i != Instances().end(); ++i )
      if( *i != this )
        (*i)->ReportRepetitions();
  }
  if( inMessage != mPrevMessage )
  {
    ReportRepetitions();
    if( inAction )
      inAction( inMessage );
    mPrevAction = inAction;
    mPrevMessage = inMessage;
  }
  else
  {
    ++mCount;
    if( ::difftime( ::time( 0 ), mLastTime ) >= cMaxTimeDiff )
      ReportRepetitions();
  }
}

void
MessageDispatcher::ReportRepetitions()
{
  Lock _( GlobalMutex() );
  if( mCount > 0 )
  {
    string message = mPrevMessage;
    if( mCount > 1 )
    {
      ostringstream oss;
      oss << " (";
      switch( mCount )
      {
        case 2:
          oss << "twice";
          break;
        default:
          oss << mCount << " times";
      }
      oss << ")";
      message += oss.str();
    }
    if( mPrevAction )
      mPrevAction( message );
  }
  mCount = 0;
  mLastTime = ::time( 0 );
}

void
MessageDispatcher::OnCheck()
{
  ReportRepetitions();
}

set<MessageDispatcher*>&
MessageDispatcher::Instances()
{
  static set<MessageDispatcher*> s;
  return s;
}

LockableObject&
MessageDispatcher::GlobalMutex()
{
  static Lockable<> mLock;
  return mLock;
}

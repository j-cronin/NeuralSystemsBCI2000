////////////////////////////////////////////////////////////////////////////////
// $Id$
// Authors: juergen.mellinger@uni-tuebingen.de
// Description: Script object type for the script interpreter.
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

#include "ScriptType.h"
#include "ScriptEvents.h"
#include "Script.h"
#include "CommandInterpreter.h"
#include "StateMachine.h"
#include "BCIException.h"
#include "BCI_OperatorLib.h"

using namespace std;
using namespace Interpreter;

ScriptType ScriptType::sInstance;
const ObjectType::MethodEntry ScriptType::sMethodTable[] =
{
  METHOD( Set ), METHOD( Clear ),
  METHOD( Get ),
  METHOD( Execute ),
  END
};

bool
ScriptType::Set( CommandInterpreter& inInterpreter )
{
  string events = inInterpreter.GetToken(),
         script = inInterpreter.GetToken();
  SetScript( inInterpreter, events, script );
  return true;
}

bool
ScriptType::Clear( CommandInterpreter& inInterpreter )
{
  string events = inInterpreter.GetToken();
  SetScript( inInterpreter, events, "" );
  return true;
}

bool
ScriptType::Get( CommandInterpreter& inInterpreter )
{
  string eventName = inInterpreter.GetToken();
  int eventID = EventID( eventName );
  string script = inInterpreter.StateMachine().EventScripts().Get( eventID );
  inInterpreter.Out() << script << endl;
  return true;
}

bool
ScriptType::Execute( CommandInterpreter& inInterpreter )
{
  string token = inInterpreter.GetToken();
  int eventID = ScriptEvents::ID( token );
  string script, name;
  if( eventID != BCI_None )
  {
    script = inInterpreter.StateMachine().EventScripts().Get( eventID );
    name = token + " script";
  }
  else
  {
    inInterpreter.Unget();
    name = inInterpreter.GetRemainder();
    ifstream file( name.c_str() );
    if( !file.is_open() )
      throw bciexception_( "Could not open script file \"" << name << "\"" );
    getline( file, script, '\0' );
  }
  Script( script, name ).Compile().Execute( CommandInterpreter( inInterpreter ) );
  return true;
}

int
ScriptType::EventID( const string& inEventName )
{
  int eventID = ScriptEvents::ID( inEventName );
  if( eventID == BCI_None )
    throw bciexception_( "Unknown scripting event: " << inEventName );
  return eventID;
}

void
ScriptType::SetScript( CommandInterpreter& inInterpreter, const string& inEvents, const string& inScript )
{
  istringstream iss( inEvents );
  string eventName;
  while( getline( iss >> ws, eventName, '|' ) )
    inInterpreter.StateMachine().EventScripts().Set( EventID( eventName ), inScript );
}

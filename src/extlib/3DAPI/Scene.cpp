////////////////////////////////////////////////////////////////////////////////
// $Id$
// Authors: shzeng, schalk@wadsworth.org, juergen.mellinger@uni-tuebingen.de
// Description: A 3D scene viewed through a rectangular region.
//
// $BEGIN_BCI2000_LICENSE$
// 
// This file is part of BCI2000, a platform for real-time bio-signal research.
// [ Copyright (C) 2000-2011: BCI2000 team and many external contributors ]
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

#include "Scene.h"

#include "GraphDisplay.h"
#include "DisplayWindow.h"
#include "BCIDirectory.h"
#include "BCIError.h"
#include "OSError.h"
#include "BCIException.h"

#if _MSC_VER
# include <direct.h>
#elif _WIN32
# include <dir.h>
#else
# include <dirent.h>
#endif

#ifndef __BORLANDC__
# include <QPainter>
#endif // __BORLANDC__

using namespace GUI;
using namespace std;

Scene::Scene( GraphDisplay& inDisplay )
: GraphObject( inDisplay, SceneDisplayZOrder ),
  mColor( RGBColor::NullColor ),
  mInitialized( false ),
  mContextHandle( NULL ),
  mfpOnCollide( NULL )
{
}

Scene::~Scene()
{
  DeleteObjects();
}

void
Scene::Add( primObj* p )
{
  if( mInitialized )
    bcierr << "Cannot add object to scene in initialized state. "
           << "Call Scene::Cleanup() to de-initialize the scene."
           << endl;
  else
    mObjects.insert( p );
}

void
Scene::Remove( primObj* p )
{
  if( mInitialized )
    bcierr << "Cannot remove object from scene in initialized state. "
           << "Call Scene::Cleanup() to de-initialize the scene."
           << endl;
  else
    mObjects.erase( p );
}

void
Scene::DeleteObjects()
{
  MakeCurrent();
  OnCleanupGL();
  while( !mObjects.empty() )
    delete *mObjects.begin();
}


void
Scene::OnPaint( const DrawContext& inDC )
{
#ifdef __BORLANDC__
  MakeCurrent();
  OnPaintGL();
  ::glFlush();
#else // __BORLANDC__
  QPainter* p = inDC.handle.painter;
  if( p && mColor != RGBColor::NullColor )
  {
    QRect r( inDC.rect.left, inDC.rect.top, inDC.rect.right - inDC.rect.left, inDC.rect.bottom - inDC.rect.top );
    p->fillRect( r, QColor( mColor.R(), mColor.G(), mColor.B() ) );
  }
  // QPainter::begin/endNativePainting saves/restores only a subset of
  // relevant GL state. When there are problems with QPainter painting
  // on top of the Scene's contents, there is probably some state missing
  // from our own save/restore code.
  if( p )
    p->beginNativePainting();
  int viewport[] = { -1, -1, -1, -1 };
  ::glGetIntegerv( GL_VIEWPORT, viewport );
  GLint shadeModel = GL_FLAT;
  ::glGetIntegerv( GL_SHADE_MODEL, &shadeModel );
  const int modes[] = { GL_MODELVIEW, GL_PROJECTION, GL_TEXTURE, GL_COLOR };
  for( int i = 0; i < sizeof( modes ) / sizeof( *modes ); ++i )
  {
    ::glMatrixMode( modes[i] );
    ::glPushMatrix();
  }
  const int caps[] = { GL_BLEND, GL_NORMALIZE, GL_CULL_FACE, GL_DEPTH_TEST, GL_LIGHTING };
  const int numCaps = sizeof( caps ) / sizeof( *caps );
  bool capValues[numCaps];
  for( int i = 0; i < numCaps; ++i )
    capValues[i] = ::glIsEnabled( caps[i] );

  ::glClearDepth( 1 );
  ::glClear( GL_DEPTH_BUFFER_BIT );

  // Viewport setup.
  const GUI::Rect& c = Display().Context().rect;
  GUI::Rect r = inDC.rect;
  r.left = ::floor( r.left );
  r.top = ::floor( r.top );
  r.bottom = ::floor( r.bottom );
  r.right = ::floor( r.right );
  r.left -= c.left;
  r.top -= c.top;
  r.right -= c.left;
  r.bottom -= c.top;
  float y = ( c.bottom - c.top ) - r.bottom;
  ::glViewport( r.left, y, r.right - r.left, r.bottom - r.top );
  OnPaintGL();

  // Restore GL state.
  for( int i = 0; i < numCaps; ++i )
  {
    if( capValues[i] )
      ::glEnable( caps[i] );
    else
      ::glDisable( caps[i] );
  }
  for( int i = 0; i < sizeof( modes ) / sizeof( *modes ); ++i )
  {
    ::glMatrixMode( modes[i] );
    ::glPopMatrix();
  }
  ::glShadeModel( shadeModel );
  ::glViewport( viewport[0], viewport[1], viewport[2], viewport[3] );
  if( p )
    p->endNativePainting();
#endif // __BORLANDC__
}

void
Scene::OnChange( DrawContext& inDC )
{
#ifdef __BORLANDC__
  if( mContextHandle != inDC.handle )
  {
    mHardwareAccelerated = false;

    Cleanup();
    if( mGLRC )
      ::wglDeleteContext( mGLRC );

    PIXELFORMATDESCRIPTOR pfd =
    {
      sizeof( PIXELFORMATDESCRIPTOR ),
      1, // Version number
      PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL,
      PFD_TYPE_RGBA,
      mBitDepth,
      0, 0, 0, 0, 0, 0, // Color bits ignored
      0, // No alpha buffer
      0, // Shift bit ignored
      0, // No accumulation buffer
      0, 0, 0, 0, // Accumulation bits ignored
      16, // 16Bit Z-Buffer (Depth buffer)
      0, // No stencil buffer
      0, // No auxiliary buffer
      PFD_MAIN_PLANE, // Main drawing layer
      0, // Reserved
      0, 0, 0 // Layer masks ignored
    };
    if( mDoubleBuffering )
      pfd.dwFlags |= PFD_DOUBLEBUFFER;

    int pixelFormat = ::ChoosePixelFormat( ( HDC )inDC.handle, &pfd );
    ::SetPixelFormat( ( HDC )inDC.handle, pixelFormat, &pfd );
    if( ::DescribePixelFormat( ( HDC )inDC.handle, pixelFormat, sizeof( PIXELFORMATDESCRIPTOR ), &pfd ) )
      mHardwareAccelerated = ( ( pfd.dwFlags & PFD_GENERIC_FORMAT ) == 0 );

    mGLRC = ::wglCreateContext( ( HDC )inDC.handle );
    MakeCurrent();
    Initialize();

    if( mDisableVsync )
    {
      mDisableVsync = false;
      // glGetString will return non-NULL only the first time it is called.
      static const char* extensions = NULL;
      if( extensions == NULL )
        extensions = ::glGetString( GL_EXTENSIONS );
      if( extensions != NULL && string( extensions ).find( "WGL_EXT_swap_control" ) != string::npos )
      {  // Switch off VSYNC if possible.
         typedef void (APIENTRY *wglSwapProc)( int );
         wglSwapProc wglSwapIntervalEXT
           = reinterpret_cast<wglSwapProc>( ::wglGetProcAddress( "wglSwapIntervalEXT" ) );
         if( wglSwapIntervalEXT != NULL )
         {
           wglSwapIntervalEXT( 0 );
           typedef int (*wglGetSwapProc)();
           wglGetSwapProc wglGetSwapIntervalEXT
             = reinterpret_cast<wglGetSwapProc>( ::wglGetProcAddress( "wglGetSwapIntervalEXT" ) );
             if( wglGetSwapIntervalEXT != NULL )
               mDisableVsync = ( wglGetSwapIntervalEXT() == 0 );
         }
      }
    }
    DoneCurrent();
  }
  mContextHandle = inDC.handle;
#else // __BORLANDC__
  if( GLContext() && mContextHandle != GLContext() )
  {
    GLContext()->makeCurrent();
    OnInitializeGL();
  }
  mContextHandle = GLContext();
#endif // __BORLANDC__

#ifdef __BORLANDC__
  MakeCurrent();
  GUI::Rect fullRect = { 0, 0, 1, 1 };
  fullRect = Display().NormalizedToPixelCoords( fullRect );
  int windowHeight = fullRect.bottom - fullRect.top;
  ::glViewport(
    inDC.rect.left,
    windowHeight - inDC.rect.bottom,
    inDC.rect.right - inDC.rect.left,
    inDC.rect.bottom - inDC.rect.top
  );
#endif // __BORLANDC__
}

void
Scene::MakeCurrent()
{
#ifdef __BORLANDC__
  ::wglMakeCurrent( ( HDC )mContextHandle, mGLRC );
#else // __BORLANDC__
  if( GLContext() )
    GLContext()->makeCurrent();
#endif // __BORLANDC__
}

void
Scene::DoneCurrent()
{
#ifdef __BORLANDC__
  ::wglMakeCurrent( 0, 0 );
#else // __BORLANDC__
  if( GLContext() )
    GLContext()->doneCurrent();
#endif // __BORLANDC__
}

void
Scene::OnInitializeGL()
{
  string cwd = BCIDirectory::GetCWD();
  if( !mImagePath.empty() )
    ::chdir( BCIDirectory::AbsolutePath( mImagePath ).c_str() );
  for( ObjectIterator i = mObjects.begin(); i != mObjects.end(); ++i )
    ( *i )->initialize();
  ::chdir( cwd.c_str() );
  mInitialized = true;
}

void
Scene::OnCleanupGL()
{
  if( mInitialized )
    for( ObjectIterator i = mObjects.begin(); i != mObjects.end(); ++i )
      ( *i )->cleanup();
  mInitialized = false;
}

void
Scene::OnPaintGL()
{
  ::glMatrixMode( GL_MODELVIEW );
  ::glLoadIdentity();
  mCameraAndLight.apply();
  ::glEnable( GL_NORMALIZE );

  DrawingOrderedSetOfObjects s;
  for( ObjectIterator i = mObjects.begin(); i != mObjects.end(); ++i )
    s.insert( *i );

  for( DrawingOrderedIterator i = s.begin(); i != s.end(); ++i )
    ( *i )->render();
}

void
Scene::Move( float inDeltaT )
{
  typedef set<sceneObj*> SetOfSceneObjects;
  typedef SetOfSceneObjects::const_iterator SceneIterator;
  SetOfSceneObjects sceneObjects;
  for( ObjectIterator i = mObjects.begin(); i != mObjects.end(); ++i )
  {
    sceneObj* p = dynamic_cast<sceneObj*>( *i );
    if( p )
      sceneObjects.insert( p );
  }
  // Apply movement
  for( SceneIterator i = sceneObjects.begin(); i != sceneObjects.end(); ++i )
    ( *i )->move( inDeltaT );
  // Test for collisions
  if( mfpOnCollide )
    for( SceneIterator i = sceneObjects.begin(); i != sceneObjects.end(); ++i )
      for( SceneIterator j = sceneObjects.begin(); j != i; ++j )
        if( sceneObj::VolumeIntersection( **i, **j ) )
          mfpOnCollide( **i, **j );

  Invalidate();
}

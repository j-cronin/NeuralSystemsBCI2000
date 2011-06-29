////////////////////////////////////////////////////////////////////////////////
// $Id: VisDisplayWindow.cpp 3307 2011-06-03 18:30:49Z mellinger $
// Authors: griffin.milsap@gmail.com, juergen.mellinger@uni-tuebingen.de
// Description: Root window class for visualization displays.
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

#include "VisDisplayWindow.h"
#include <QApplication>
#include <QDesktopWidget>

using namespace std;

QWidget* VisDisplayWindow::spParentWindow = NULL;

VisDisplayWindow::VisDisplayWindow( const std::string& inVisID )
: VisDisplayBase( inVisID )
{
  this->setParent( spParentWindow, Qt::Tool );
  this->setAttribute( Qt::WA_MacAlwaysShowToolWindow, true );
  SetConfig( Visconfigs()[ mVisID ] );
  mLayout = new QStackedLayout( this );
  mLayout->setGeometry( QRect( 0, 0, this->width(), this->height() ) );
  mLayout->setStackingMode( QStackedLayout::StackAll );
  mLayout->setParent( this );
  this->setLayout( mLayout );

  // All VisDisplayWindows have a black background for backward compatibility
  // Note: This palette will propogate to child QWidgets.
  QPalette pal = this->palette();
  pal.setBrush( QPalette::Window, QBrush( Qt::black ) );
  pal.setBrush( QPalette::WindowText, QBrush( Qt::white ) );
  this->setPalette( pal );
  this->update();
}

VisDisplayWindow::~VisDisplayWindow()
{
  // When destructing a window, child QWidgets will be automatically deleted.
  string base = mVisID.substr( 0, mVisID.find( ":" ) + 1 );
  for( VisContainerBase::iterator vitr = Visuals().begin(); vitr != Visuals().end(); vitr++ )
    if( vitr->first.find( base ) != string::npos )
      vitr->second = NULL;  
  delete mLayout; // May be automatically deleted...
}

void
VisDisplayWindow::SetConfig( ConfigSettings& inConfig )
{ 
  mUserIsMoving = false;
  mTitle = inConfig[ CfgID::WindowTitle ];
  if( !mTitle.empty() )
    this->setWindowTitle( mTitle.c_str() );
  else
    this->setWindowTitle( mVisID.c_str() );

  // The static variables make each new window appear a little down right
  // from the previous one.
  static int newTop = 10,
             newLeft = 10;
  int formTop = 10,
      formLeft = 10,
      formHeight = 100,
      formWidth = 100;
  bool posDefault  = !inConfig.Get( CfgID::Top, formTop ) ||
                     !inConfig.Get( CfgID::Left, formLeft ),
       sizeDefault = !inConfig.Get( CfgID::Height, formHeight ) ||
                     !inConfig.Get( CfgID::Width, formWidth );
  if( posDefault )
  {
    formTop = newTop;
    newTop += 10;
    formLeft = newLeft;
    newLeft += 10;
  }
  if( formWidth <= 10 || formHeight <= 10 )
  {
    sizeDefault = true;
    formHeight = 100;
    formWidth = 100;
  }
  int desktopWidth = QApplication::desktop()->width(),
      desktopHeight = QApplication::desktop()->height();
  if( formTop < 0 || formLeft < 0 
      || formTop >= desktopHeight || formLeft >= desktopWidth )
  {
    posDefault = true;
    formTop = newTop;
    newTop += 10;
    formLeft = newLeft;
    newLeft += 10;
  }
  this->move( formLeft, formTop );
  this->resize( formWidth, formHeight );
  if( posDefault )
  {
    Visconfigs()[ mVisID ].Put( CfgID::Top, formTop, Default );
    Visconfigs()[ mVisID ].Put( CfgID::Left, formLeft, Default );
  }
  if( sizeDefault )
  {
    Visconfigs()[ mVisID ].Put( CfgID::Width, formWidth, Default );
    Visconfigs()[ mVisID ].Put( CfgID::Height, formHeight, Default );
  }
  VisDisplayBase::SetConfig( inConfig );
  mUserIsMoving = true;
}

void
VisDisplayWindow::moveEvent( QMoveEvent* iopEvent )
{
  if( mUserIsMoving )
  {
    Visconfigs()[ mVisID ].Put( CfgID::Top, this->pos().y(), UserDefined );
    Visconfigs()[ mVisID ].Put( CfgID::Left, this->pos().x(), UserDefined );
  }
  QWidget::moveEvent( iopEvent );
}

void
VisDisplayWindow::resizeEvent( QResizeEvent* iopEvent )
{
  this->update();
  if( mUserIsMoving )
  {
    Visconfigs()[ mVisID ].Put( CfgID::Width, this->size().width(), UserDefined );
    Visconfigs()[ mVisID ].Put( CfgID::Height, this->size().height(), UserDefined );
  }
  QWidget::resizeEvent( iopEvent );
}
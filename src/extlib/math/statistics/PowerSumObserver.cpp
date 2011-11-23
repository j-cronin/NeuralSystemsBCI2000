////////////////////////////////////////////////////////////////////////////////
// $Id$
// Author: juergen.mellinger@uni-tuebingen.de
// Description: See the header file for documentation.
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

#include "PowerSumObserver.h"

using namespace std;
using namespace StatisticalObserver;

PowerSumObserver::PowerSumObserver( int inConfig )
: ObserverBase( inConfig, Supports ),
  mCovarianceRequired( ImpliedConfig( inConfig ) & StatisticalObserver::Covariance ),
  mPowerSum0( 0 )
{
}

void
PowerSumObserver::DoChange()
{
  if( mPowerSum1.size() != SampleSize() )
    DoClear();
}

void
PowerSumObserver::DoAgeBy( unsigned int inCount )
{
  if( DecayFactor() == 1 )
    return;

  Number factor = ::pow( DecayFactor(), static_cast<int>( inCount ) );
  mPowerSum0 *= factor;
  mPowerSum1 *= factor;
  mPowerSum2Diag *= factor;
  mPowerSum2Full *= factor;
}

void
PowerSumObserver::DoObserve( const Vector& inV, Number inWeight )
{
  mPowerSum0 += inWeight;
  mPowerSum1 += inV * inWeight;
  mPowerSum2Diag += inV * inV * inWeight;
  if( mCovarianceRequired )
    mPowerSum2Full += ( OuterProduct( inV, inV ) *= inWeight );
}

void
PowerSumObserver::DoClear()
{
  mPowerSum0 = 0;
  mPowerSum1.resize( 0 );
  mPowerSum2Diag.resize( 0 );
  mPowerSum2Full.resize( 0 );
  mPowerSum1.resize( SampleSize() );
  mPowerSum2Diag.resize( SampleSize() );
  if( mCovarianceRequired )
    mPowerSum2Full.resize( SampleSize(), Vector( SampleSize() ) );
}

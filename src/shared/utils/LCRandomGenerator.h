////////////////////////////////////////////////////////////////////////////////
// $Id$
// Authors: juergen.mellinger@uni-tuebingen.de
// Description: A class that encapsulates a Linear Congruential Pseudo Random
//   number generator.
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
#ifndef LC_RANDOM_GENERATOR_H
#define LC_RANDOM_GENERATOR_H

#include <string>
#include <stdint.h>

class LCRandomGenerator
{
 public:
  typedef uint32_t SeedType;
  typedef uint32_t NumberType;

  LCRandomGenerator() : mSeed( DefaultSeed() ) {}
  LCRandomGenerator( SeedType s ) : mSeed( s ) {}
  SeedType DefaultSeed();
  // Properties
  SeedType Seed() const { return mSeed; }
  LCRandomGenerator& SetSeed( SeedType s ) { mSeed = s; return *this; }

  NumberType RandMax() const;
  // This returns a random integer between 0 and including RandMax().
  NumberType Random();
 
  // STL functor interface: operator() returns a random integer between 0 and (N-1).
  template<typename Int> Int operator()( Int inN )
    { return ( Random() * inN ) / ( RandMax() + 1 ); }
  std::string RandomName( size_t inLength );
  char RandomCharacter( int (*)( int ) = &::isalpha );

 private:
  static NumberType NumberFromSeed( SeedType );

  SeedType mSeed;
};

#endif // LC_RANDOM_GENERATOR_H
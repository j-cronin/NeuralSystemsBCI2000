////////////////////////////////////////////////////////////////////////////////
// $Id$
// Author: juergen.mellinger@uni-tuebingen.de
// Description: A filter chain wrapper that provides an environment for
//   GenericFilter descendants, independent of parameters and states in the
//   global environment.
//   This allows BCI2000 filters to be used independently of the main processing
//   chain, e.g. for processing visualization data.
//
//   After instantiating a StandaloneChain, use AddFilter<>() to populate its
//   list of filters. Once the chain is populated, set its parameters using the
//   Parameter() function. Then, call SetConfig() to apply the current set of
//   parameters. Call Start() to begin processing, and Process() for each block
//   of data. When finished with processing, call Stop().
//
//   For convenience in situations where only a single filter is to be used,
//   there exists a Standalone class template.
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
#ifndef STANDALONE_FILTERS_H
#define STANDALONE_FILTERS_H

#include "Uncopyable.h"
#include "GenericFilter.h"

class StandaloneChain : private EnvironmentBase, Uncopyable
{
 public:
  StandaloneChain();
  virtual ~StandaloneChain();

  // Populate the list of filters by calling AddFilter in the desired order of
  // processing.
  template<class T> void AddFilter();  

  // Access to parameters. Call SetConfig() to apply changed parameters.
  ParamList& Parameters() { return *EnvironmentBase::Parameters; }
  ParamRef Parameter( const std::string& s ) { return EnvironmentBase::Parameter( s ); }
  // Access to states.
  StateList& States() { return *EnvironmentBase::States; }
  StateRef State( const std::string& s ) { return EnvironmentBase::State( s ); }

  // For efficiency reasons, the output signal is stored inside the chain.
  const GenericSignal& Output() const { return mSignals.back(); }
  // Call SetConfig() to configure the filter. Use the first argument to tell
  // the filter about its input signal, and receive information about its output
  // signal in the second argument.
  bool SetConfig( const SignalProperties& );
  // After successful configuration, call Start() once to initiate processing.
  void Start();
  // Call Process() for each block of data.
  void Process( const GenericSignal& );
  // When finished with processing, call Stop().
  void Stop();

 private:
  void DoAddFilter( GenericFilter* );
  void DoPreflightInitialize( const SignalProperties& );
  
  enum { uninitialized, suspended, running } mChainState;
  
  std::vector<GenericFilter*> mFilters;
  std::vector<GenericSignal> mSignals;
  
  ParamList mParameters;
  StateList mStates;
  StateVector mStatevector;
};

template <typename T>
struct StandaloneFilter : StandaloneChain
{
  StandaloneFilter() { AddFilter<T>(); }
};


// Implementation
template<class T>
void
StandaloneChain::AddFilter()
{
  GenericFilter* pFilter = NULL;
  {
    EnvironmentBase::WrapperContext temp( this );
    pFilter = new T;
  }
  DoAddFilter( pFilter );
}

#endif // STANDALONE_FILTERS_H

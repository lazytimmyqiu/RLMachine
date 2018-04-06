#pragma once

#include <limits>
#include "Environment.h"

namespace RLMachine {

class TestEnv : public Environment<index_t, index_t>
{
public:
  void Init()
  {
    state_ = 0;
    r_ = std::numeric_limits<real_t>::lowest(); 
  }

  void Finalize()
  {
    state_ = 0;
    r_ = std::numeric_limits<real_t>::lowest(); 
  }

  // stop if state reach 10
  bool IsQuit() { return state_ == 10; }

  void Step(const index_t& a);
};

}


#pragma once

#include "base.h"

// Base class for environments

namespace RLMachine {

template <typename State, typename Action>
class Environment
{
  virtual ~Environment() {}

  virtual void step(const State& s, const Action& a, State& s_next, real_t& r) = 0;
};

}

#pragma once

#include "base.h"

// Base class for environments

namespace RLMachine {

template <typename State, typename Action>
class Environment
{
public:
  virtual ~Environment() {}

  virtual void Step(const State& s, const Action& a, State& s_next, real_t& r) = 0;
};

}

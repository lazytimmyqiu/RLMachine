#pragma once

#include "common.h"

// Base class for environments

namespace RLMachine {

template <typename State, typename Action>
class Environment
{
public:
  Environment() : b_quit_(false) {}

  virtual ~Environment() {}

  virtual void Step(const State& s, const Action& a, State& s_next, real_t& r) = 0;

  virtual bool  is_quit() { return b_quit_; }

private:
  bool b_quit_;
};


}

#pragma once

#include "common.h"

namespace RLMachine {

// Base class for agent

template<typename State, typename Action>
class Agent
{
public:
  Agent() : b_quit_(false) {}

  virtual ~Agent() {}
    
  virtual void Step(const State&s, real_t r, Action& a) = 0;

  virtual bool is_quit() { return b_quit_; }

private:
  bool  b_quit_;

};

}


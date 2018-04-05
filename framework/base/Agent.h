#pragma once

#include "common.h"

namespace RLMachine {

// Base class for agent

template<typename State, typename Action>
class Agent
{
public:
  virtual ~Agent() {}
    
  virtual void Step(const State&s, real_t r, Action& a) = 0;

};

}


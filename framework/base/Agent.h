#pragma once

#include "common.h"

namespace RLMachine {

// Base class for agent

template<typename State, typename Action>
class Agent
{
public:
  Agent() : G_(0.0), t_(0) {}

  virtual ~Agent() {}

  virtual void Init() = 0;

  virtual void Finalize() = 0;

  virtual bool IsQuit() = 0;
  
  virtual void Step(const State&s, real_t r) = 0;

  virtual real_t GetReturn() { return G_; }

  virtual const Action& GetAction() const
  { return a_; }

protected:
  Action a_;

  real_t G_;

  index_t t_;
};

}


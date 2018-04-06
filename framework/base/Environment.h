#pragma once

#include "common.h"

// Base class for environments

namespace RLMachine {

template <typename State, typename Action>
class Environment
{
public:
  virtual ~Environment() {}

  virtual void Init() = 0;

  virtual void Finalize() = 0;

  virtual const State& GetState() const
  { return state_; }

  virtual real_t GetReward() const
  { return r_; }

  virtual bool  IsQuit() = 0;

  virtual void Step(const Action& a) = 0;

protected:
  State state_;
  index_t r_;
};


}

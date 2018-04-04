#pragma once

#include <limits>
#include "base.h"
#include "Environment.h"
#include "Agent.h"

namespace RLMachine {

template<typename State, typename Action>
class RLContext
{
public:
  // 初始化环境模型和Agent模型
  RLContext(Environment<State, Action>* e, Agent<State, Action>* a) 
  : env_(e), agent_(a), r_(std::numeric_limits<real_t>::lowest())
  {
  }

  virtual ~RLContext() {}

  // 分别调用Agent模型和环境模型的Step方法，完成一次交互
  void Step(); 

private:
  Environment<State, Action>* env_;
  Agent<State, Action>* agent_;

  State state_;
  real_t r_;
};

}


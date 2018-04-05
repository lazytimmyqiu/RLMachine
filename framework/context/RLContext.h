#pragma once

#include <limits>
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


/* template definition */

template<typename State, typename Action>
void RLContext<State, Action>::Step()
{
  // Agent根据初始state和奖励做出动作
  Action a;
  agent_->Step(state_, r_, a);
  
  // Environment返回下一个状态和Reward
  State s(state_);  // 保存上一个状态
  env_->Step(s, a, state_, r_);
}


}


#pragma once

#include "Environment.h"
#include "Agent.h"

namespace RLMachine {

template<typename State, typename Action>
class RLContext
{
public:
  // 初始化环境模型和Agent模型
  RLContext(Environment<State, Action>* e, Agent<State, Action>* a) 
  : env_(e), agent_(a)
  {
  }

  virtual ~RLContext() {}

  // 分别调用Agent模型和环境模型的Step方法，完成一次交互
  void Step(); 

private:
  Environment<State, Action>* env_;
  Agent<State, Action>* agent_;
};


/* template definition */

template<typename State, typename Action>
void RLContext<State, Action>::Step()
{
  // Agent根据初始state和奖励做出动作
  agent_->Step(env_->GetState(), env_->GetReward());
  
  // Environment返回Reward, 同时更新自己的State
  env_->Step(agent_->GetAction());
}


}


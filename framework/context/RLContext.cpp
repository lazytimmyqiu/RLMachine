#include "RLContext.h"

using namespace RLMachine;

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

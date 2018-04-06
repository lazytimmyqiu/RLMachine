#include "RLContext.h"
#include "Logger.h"

using namespace RLMachine;
using TLib::Logger;
using TLib::INFO;

namespace RLMachine {
  // 环境实例和Agent实例声明
  extern Environment<index_t, index_t>* g_pEnv;
  extern Agent<index_t, index_t>* g_pAgent;
}


int main()
{
  // 测试Logger
  TLOG(INFO) << "Test log. " << endl;

  // 创建Context
  g_pEnv->Init();
  g_pAgent->Init();
  RLContext<index_t, index_t> rlc(g_pEnv, g_pAgent);

  // learning loop
  // stop if env or agent the quit flag
  TLOG(INFO) << "Initial state: " << g_pEnv->GetState() << ", reward: " << g_pEnv->GetReward() << endl;
  while(!g_pEnv->IsQuit() && !g_pAgent->IsQuit()) {
    rlc.Step();
    TLOG(INFO) << "Agent action: " << g_pAgent->GetAction() << endl;
    TLOG(INFO) << "Environment response, state: " << g_pEnv->GetState() << ", reward: " << g_pEnv->GetReward() << endl;
  }

  if (g_pEnv->IsQuit())
    TLOG(INFO) << "Envionment's stop criterion is met" << endl;

  if (g_pAgent->IsQuit())
    TLOG(INFO) << "Agent's stop criterion is met" << endl;

  return 0;
}

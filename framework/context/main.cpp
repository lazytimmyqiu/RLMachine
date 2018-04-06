#include "RLContext.h"
#include "Logger.h"

using namespace RLMachine;
using TLib::Logger;
using TLib::LogLevel;

namespace RLMachine {
  // 环境实例和Agent实例声明
  extern Environment<index_t, index_t>* g_pEnv;
  extern Agent<index_t, index_t>* g_pAgent;
}


int main()
{
  // 测试Logger
  TLOG(LogLevel::INFO) << "Test log. " << endl;

  // 创建Context
  RLContext<index_t, index_t> rlc(g_pEnv, g_pAgent);

  // learning loop
  // stop if env or agent set the quit flag
  while(!g_pEnv->is_quit() && !g_pAgent->is_quit()) {
    rlc.Step();
  }


  return 0;
}

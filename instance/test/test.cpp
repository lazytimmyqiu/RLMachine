#include "TestEnv.h"
#include "TestAgent.h"

namespace RLMachine {
  TestEnv g_Env;
  Environment<index_t, index_t>* g_pEnv = &g_Env;

  TestAgent g_Agent;
  Agent<index_t, index_t>* g_pAgent = &g_Agent;
}

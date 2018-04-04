#include "TestEnv.h"

using namespace RLMachine;

void TestEnv::Step(const index_t& s, const index_t& a, index_t& s_next, real_t& r)
{
  s_next = s + 1;   
  r = 1;
}

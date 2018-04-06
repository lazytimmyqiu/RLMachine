#include "TestAgent.h"

using namespace RLMachine;

void TestAgent::Step(const index_t&s, real_t r)
{
  a_ = 1;
  G_ += r;
}


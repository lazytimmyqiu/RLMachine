#include "TestEnv.h"

using namespace RLMachine;

void TestEnv::Step(const index_t& a)
{
  // state transition
  ++state_;

  // all always reward 1
  r_ = 1;
}

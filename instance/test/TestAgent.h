#pragma once

#include "Agent.h"

namespace RLMachine {
  
class TestAgent : public Agent<index_t, index_t>
{
public:
  TestAgent(): Agent<index_t, index_t>() {}

  void Init() {}

  void Finalize() {}

  // don't quit for test case
  bool IsQuit() { return false; }

  void Step(const index_t&s, real_t r);
};


}

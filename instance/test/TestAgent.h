#pragma once

#include "Agent.h"

namespace RLMachine {
  
class TestAgent : public Agent<index_t, index_t>
{

public:
  void Step(const index_t&s, real_t r, index_t& a);
};

}

#pragma once

#include "Environment.h"
#include "base.h"

namespace RLMachine {

class TestEnv : public Environment<index_t, index_t> {

public:
  void Step(const index_t& s, const index_t& a, index_t& s_next, real_t& r);
};

}


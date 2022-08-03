#pragma once

#include "structures.hpp"

struct Register { private: Register(); };
struct DeclareRegister : Register { explicit DeclareRegister(int id); };

void inc(Register);
void mv(Register, Source source);
RegisterSource rd(Register);

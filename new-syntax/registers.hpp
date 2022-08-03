#pragma once

#include "source.hpp"
#include "declare.hpp"
#include "macro-utils.hpp"


struct(Register, private: Register();)
structp(DeclareRegister, (Register), explicit DeclareRegister(int id);)

declare(RegisterSource, rd(Register id), R(id))
declare(void, inc(Register id), I(id))
declare(void, mv(Register id, Source source), source => W(id))

#pragma once

#include "macro-utils.hpp"

#define inc(id) I(id)
#define mv(id, source) source => W(id)
#define rd(id) R(id)

#define DeclareRegister(id) id
#define Register

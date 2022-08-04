#pragma once

#include "syntax/module.hpp"

#define result result

#ifdef TRANSLATE

#include "syntax/registers-translate.hpp"
#include "syntax/alu-translate.hpp"
#include "syntax/jump-translate.hpp"
#include "syntax/cycle-translate.hpp"
#include "syntax/branching-translate.hpp"
#include "syntax/procedure-translate.hpp"
#include "syntax/critical-translate.hpp"
#include "syntax/exit-translate.hpp"
#include "syntax/structures-translate.hpp"

#define LOOP_START
#define LOOP_END

#else

#include "syntax/structures.hpp"
#include "syntax/registers.hpp"
#include "syntax/alu.hpp"
#include "syntax/jump.hpp"
#include "syntax/cycle.hpp"
#include "syntax/branching.hpp"
#include "syntax/procedure.hpp"
#include "syntax/critical.hpp"
#include "syntax/exit.hpp"

#define LOOP_START int main() {
#define LOOP_END }

#endif

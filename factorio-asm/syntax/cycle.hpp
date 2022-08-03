#pragma once

#include "structures.hpp"
#include "jump.hpp"

#define while _cycle_check
#define while_not _cycle_check
#define do_while _cycle_check
#define do_while_not _cycle_check

#define _cycle_check(condition, source, ...) _isCondition(condition); _isSource(source); {__VA_ARGS__}

#pragma once

#include "structures.hpp"
#include "jump.hpp"

#define if(condition, source, ...) _isCondition(condition); _isSource(source); {__VA_ARGS__}
#define if_not(condition, source, ...) _isCondition(condition); _isSource(source); {__VA_ARGS__}

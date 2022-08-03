#pragma once

#include "macro-utils.hpp"

#define critical(...) _SUBSTITUTE_ARGS(_critical, __COUNTER__, __VA_ARGS__)
#define _critical(id, ...) \
	__critical_begin_##id: \
	__VA_ARGS__ \
	__critical_end_##id:

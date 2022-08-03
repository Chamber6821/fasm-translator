#pragma once

#include "../syntax.hpp"

#define foreach(variable, collection, ...) \
	while_not(zero, rd(collection), \
		calc(variable, rd(collection), any_one); \
		assignOpposite(variable); \
		combineAssign(collection, rd(variable)); \
		__VA_ARGS__ \
	)
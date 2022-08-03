#include "translator.hpp"

#define result result

#define foreach(variable, collection, ...) \
	while_not(zero, rd(collection), \
		calc(variable, rd(collection), any_one); \
		assignOpposite(variable); \
		combineAssign(collection, rd(variable)); \
		__VA_ARGS__ \
	)

procedure(assignOpposite, (Register reg), calcAssign(reg, mult, -1);)

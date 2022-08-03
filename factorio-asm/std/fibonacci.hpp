#include "../syntax.hpp"

procedure(fibonacci, (Register current, Register reg1, Register reg2),
	#define current current
	#define next	reg1
	#define temp 	reg2

	mv(current, 0);
	mv(next, 1);

	while_not(any_negative, rd(next),
		mv(temp, rd(next));
		calcAssign(next, add, rd(current));
		mv(current, rd(temp));
	)
)
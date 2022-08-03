#pragma once

#include "../syntax.hpp"

procedure(assert, (Condition condition, Register reg),
	if (condition, rd(reg),
		exit(reg);
	)
)
#include "macro-utils.hpp"

#ifdef TRANSLATE
#include "replace-words.hpp"
_INNER_MACRO(include) "new-syntax/macro-utils.hpp"
#endif

#include "alu.hpp"
#include "jump.hpp"
#include "cycle.hpp"

void foo() {
	#define reg1 DeclareRegister(1)
	
	"Это коментарий к коду";
	calc(reg1, rd(reg1), mult, rd(reg1));
	calc(reg1, rd(reg1), any_one);
	calc(reg1, 1, any_one);

	calcAssign(reg1, any_one);

	while(all_positive, rd(reg1),
		calcAssign(reg1, mult, 2);
	)

	#define reg DeclareRegister(2)

	a: jz(a, rd(reg));
}

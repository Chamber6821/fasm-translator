#pragma once

#include "structures.hpp"

#define jmp(tag) goto tag
#define jmp_if(tag, source, condition) _isCondition(condition); _cjump(tag, source)
#define jz(tag, source) _cjump(tag, source)  // all (z)ero
#define jln(tag, source) _cjump(tag, source) // a(l)l (n)egative
#define jlp(tag, source) _cjump(tag, source) // a(l)l (p)ositive
#define jnn(tag, source) _cjump(tag, source) // a(n)y (n)egative
#define jnp(tag, source) _cjump(tag, source) // a(n)y (p)ositive
#define jng(tag, source) _cjump(tag, source) // (n)o (g)reen
#define jg(tag, source) _cjump(tag, source)  // (g)reen

#define _cjump(tag, source) _isSource(source); goto tag

enum Condition
{
	zero,
	all_positive,
	all_negative,
	any_positive,
	any_negative,
	no_green,
	green
};

void _isCondition(Condition);

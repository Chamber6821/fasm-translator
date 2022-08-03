#pragma once

#include "module.hpp"
#include "declare.hpp"
#include "source.hpp"
#include "macro-utils.hpp"

enum(Condition)
	enumerator(zero, C2)
	enumerator(all_negative, C3)
	enumerator(all_positive, C4)
	enumerator(any_negative, C5)
	enumerator(any_positive, C6)
	enumerator(no_green, C7)
	enumerator(green, C8)
end

declareStub(void, _isCondition(Condition))


#define jmp(tag) \
	_EDITOR_IMPL(goto tag) \
	_TRANSLATION_IMPL(C1 J(tag))

#define jmp_if(tag, source, condition) \
	_EDITOR_IMPL(_isSource(source); _isCondition(condition); goto tag) \
	_TRANSLATION_IMPL((condition source) J(tag))

#define jz(tag, source) jmp_if(tag, source, zero)          // all (z)ero
#define jln(tag, source) jmp_if(tag, source, all_negative) // a(l)l (n)egative
#define jlp(tag, source) jmp_if(tag, source, all_positive) // a(l)l (p)ositive
#define jnn(tag, source) jmp_if(tag, source, any_negative) // a(n)y (n)egative
#define jnp(tag, source) jmp_if(tag, source, any_positive) // a(n)y (p)ositive
#define jng(tag, source) jmp_if(tag, source, no_green)     // (n)o (g)reen
#define jg(tag, source) jmp_if(tag, source, green)         // (g)r

#pragma once

#define jmp(tag) C1 J(tag)
#define jmp_if _cjump
#define jz(tag, source) _cjump(tag, source, zero)          // all (z)ero
#define jln(tag, source) _cjump(tag, source, all_negative) // a(l)l (n)egative
#define jlp(tag, source) _cjump(tag, source, all_positive) // a(l)l (p)ositive
#define jnn(tag, source) _cjump(tag, source, any_negative) // a(n)y (n)egative
#define jnp(tag, source) _cjump(tag, source, any_positive) // a(n)y (p)ositive
#define jng(tag, source) _cjump(tag, source, no_green)     // (n)o (g)reen
#define jg(tag, source) _cjump(tag, source, green)         // (g)reen

#define _cjump(tag, source, condition) (source condition) J(tag)

#define Condition
#define zero         C2
#define all_negative C3
#define all_positive C4
#define any_negative C5
#define any_positive C6
#define no_green     C7
#define green        C8

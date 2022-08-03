#pragma once

#include "jump-translate.hpp"
#include "macro-utils.hpp"

#define while(condition, source, ...) _SUBSTITUTE_ARGS(__while_with_id, __COUNTER__, source, condition, __VA_ARGS__)
#define __while_with_id(id, source, condition, ...) \
__wl##id: \
jmp_if(__wlb##id, source, condition); \
jmp(__wle##id); \
__wlb##id: \
__VA_ARGS__ \
jmp(__wl##id); \
__wle##id:

#define while_not(condition, source, ...) _SUBSTITUTE_ARGS(__while_not_with_id, __COUNTER__, source, condition, __VA_ARGS__)
#define __while_not_with_id(id, source, condition, ...) \
__wln##id: \
jmp_if(__wlne##id, source, condition); \
__VA_ARGS__ \
jmp(__wln##id); \
__wlne##id:

#define do_while(condition, source, ...) _SUBSTITUTE_ARGS(__do_while_with_id, __COUNTER__, source, condition, __VA_ARGS__)
#define __do_while_with_id(id, source, condition, ...) \
__dwl##id: \
__VA_ARGS__ \
jmp_if(__dwl##id, source, condition);

#define do_while_not(condition, source, ...) _SUBSTITUTE_ARGS(__do_while_not_with_id, __COUNTER__, source, condition, __VA_ARGS__)
#define __do_while_not_with_id(id, source, condition, ...) \
__wln##id: \
__VA_ARGS__ \
jmp_if(__wlne##id, source, condition); \
jmp(__wln##id); \
__wlne##id:

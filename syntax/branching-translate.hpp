#pragma once

#include "jump-translate.hpp"
#include "macro-utils.hpp"

#define if(condition, source, ...) _SUBSTITUTE_ARGS(__if_with_id, __COUNTER__, condition, source, __VA_ARGS__)
#define __if_with_id(id, condition, source, ...) \
jmp_if(__ifb##id, source, condition); \
jmp(__ife##id); \
__ifb##id: \
__VA_ARGS__ \
__ife##id:

#define if_not(condition, source, ...) _SUBSTITUTE_ARGS(__if_not_with_id, __COUNTER__, condition, source, __VA_ARGS__)
#define __if_not_with_id(id, condition, source, ...) \
jmp_if(__ife##id, source, condition); \
__VA_ARGS__ \
__ife##id:

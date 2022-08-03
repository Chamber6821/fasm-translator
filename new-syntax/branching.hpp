#pragma once

#include "source.hpp"
#include "jump.hpp"
#include "macro-utils.hpp"

#define if(condition, source, ...) \
	_EDITOR_IMPL(_isCondition(condition); _isSource(source); {__VA_ARGS__}) \
	_TRANSLATION_IMPL(_SUBSTITUTE_ARGS(__if_with_id, __COUNTER__, condition, source, __VA_ARGS__))

#define __if_with_id(id, condition, source, ...) \
	jmp_if(__ifb##id, source, condition); \
	jmp(__ife##id); \
	__ifb##id: \
	__VA_ARGS__ \
	__ife##id:


#define if_not(condition, source, ...) \
	_EDITOR_IMPL(_isCondition(condition); _isSource(source); {__VA_ARGS__}) \
	_TRANSLATION_IMPL(_SUBSTITUTE_ARGS(__if_not_with_id, __COUNTER__, condition, source, __VA_ARGS__))

#define __if_not_with_id(id, condition, source, ...) \
	jmp_if(__ife##id, source, condition); \
	__VA_ARGS__ \
	__ife##id:

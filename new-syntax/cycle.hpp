#pragma once

#include "jump.hpp"
#include "branching.hpp"
#include "macro-utils.hpp"


#define _cycle_check(condition, source, ...) _isCondition(condition); _isSource(source); {__VA_ARGS__}


#define while(condition, source, ...) \
	_EDITOR_IMPL(_cycle_check(condition, source, __VA_ARGS__)) \
	_TRANSLATION_IMPL(_SUBSTITUTE_ARGS(__while_with_id, __COUNTER__, source, condition, __VA_ARGS__))
#define __while_with_id(id, source, condition, ...) \
	__wl##id: \
	if(condition, source, __VA_ARGS__) \
	jmp(__wl##id);


#define while_not(condition, source, ...) \
	_EDITOR_IMPL(_cycle_check(condition, source, __VA_ARGS__)) \
	_TRANSLATION_IMPL(_SUBSTITUTE_ARGS(__while_not_with_id, __COUNTER__, source, condition, __VA_ARGS__))
#define __while_not_with_id(id, source, condition, ...) \
	__wln##id: \
	if_not(condition, source, __VA_ARGS__) \
	jmp(__wl##id);


#define do_while(condition, source, ...) \
	_EDITOR_IMPL(_cycle_check(condition, source, __VA_ARGS__)) \
	_TRANSLATION_IMPL(_SUBSTITUTE_ARGS(__do_while_with_id, __COUNTER__, source, condition, __VA_ARGS__))
#define __do_while_with_id(id, source, condition, ...) \
	__dwl##id: \
	__VA_ARGS__ \
	jmp_if(__dwl##id, source, condition);


#define do_while_not(condition, source, ...) \
	_EDITOR_IMPL(_cycle_check(condition, source, __VA_ARGS__)) \
	_TRANSLATION_IMPL(_SUBSTITUTE_ARGS(__do_while_not_with_id, __COUNTER__, source, condition, __VA_ARGS__))
#define __do_while_not_with_id(id, source, condition, ...) \
	__wln##id: \
	__VA_ARGS__ \
	if_not(condition, source, jmp(__wln##id);)

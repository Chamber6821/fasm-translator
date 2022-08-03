#pragma once

#include "macro-utils.hpp"

#define module(name) \
	_EDITOR_IMPL(namespace name {) \
	_TRANSLATION_IMPL(_INNER_MACRO(define) name)

#define member(type, signature, macro_value) \
	_EDITOR_IMPL(type signature;) \
	_TRANSLATION_IMPL(_INNER_MACRO(define) signature macro_value)

#define enum(name) _EDITOR_IMPL(enum name {)

#define enumerator(name, macro_value) \
	_EDITOR_IMPL(name,) \
	_TRANSLATION_IMPL(_INNER_MACRO(define) name macro_value)

#define _SEMICOLON ;
#define end _EDITOR_IMPL(} _SEMICOLON)

#define struct(name, ...) _EDITOR_IMPL(struct name { __VA_ARGS__ };)
#define structp(name, parents, ...) _EDITOR_IMPL(struct name : _UNESCAPE_BRACKET parents { __VA_ARGS__ };)

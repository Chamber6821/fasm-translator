#pragma once

#include "macro-utils.hpp"

#define _QUOTE "
#define declareImpl(signature, macro_value) _TRANSLATION_IMPL(_INNER_MACRO(define) signature _QUOTE macro_value _QUOTE)
#define declareImpl2(signature, macro_value) _TRANSLATION_IMPL(_INNER_MACRO(define) signature macro_value)
#define declareStub(return_type, signature) _EDITOR_IMPL(return_type signature;)

#define declare(return_type, signature, macro_value) \
	_EDITOR_IMPL(return_type signature;) \
	_TRANSLATION_IMPL(_INNER_MACRO(define) signature macro_value)

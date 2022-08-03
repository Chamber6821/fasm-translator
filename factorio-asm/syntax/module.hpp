#pragma once

#ifdef TRANSLATE

#include "macro-utils.hpp"

#define module(name) _INNER_MACRO(define) name
#define member(type, signature, macro_value) _INNER_MACRO(define) signature macro_value

#define enum(name) _INNER_MACRO(define) name
#define enumerator(name, macro_value) _INNER_MACRO(define) name macro_value

#define end

#else

#define module(name) namespace name {
#define member(type, signature, macro_value) type signature;

#define enum(name) enum name {
#define enumerator(name, macro_value) name,

#define _SEMICOLON ;
#define end } _SEMICOLON

#endif

#pragma once

#include "macro-utils.hpp"

#define procedure(name, args, ...) _INNER_MACRO(define) name(_UNESCAPE_BRACKET args) __VA_ARGS__

#pragma once

#define _SUBSTITUTE_ARGS(FUNC, ...) FUNC(__VA_ARGS__)

#define _HASHTAG #
#define _INNER_MACRO(macro) _HASHTAG macro // скрипт повторно прогонит текст через препроцессор для обработки этого

#define _UNESCAPE_BRACKET(...) __VA_ARGS__

#define _MERGE(a, b) a##b

#define _OVERLOAD_ARG4(arg1, arg2, arg3, arg4, FUNC, ...) FUNC

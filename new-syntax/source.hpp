#pragma once

#include "declare.hpp"
#include "macro-utils.hpp"

struct(Source, Source(); Source(int);)
structp(RegisterSource, (Source), RegisterSource(int number);)

declareStub(void, _isSource(Source))

#pragma once

#include "module.hpp"
#include "registers.hpp"
#include "declare.hpp"
#include "macro-utils.hpp"

enum(BinOperation)
	enumerator(add, G1)
	enumerator(sub, G2)
	enumerator(mult, G3)
	enumerator(div, G4)
	enumerator(mod, G5)
end

enum(UnarOperation)
	enumerator(total, G16)
	enumerator(single, G17)
	enumerator(any_one, G18)
end


declare(void, mvL(RegisterSource source), source => (U1 M1))
declare(void, mvR(RegisterSource source), source => (U1 M2))
declare(Source, res(BinOperation operation), (U1 operation))
declareStub(Source, res(UnarOperation))

declareStub(void, calc(Register out, RegisterSource left, BinOperation, RegisterSource right))
declareStub(void, calc(Register out, RegisterSource left, UnarOperation))
declareImpl(calc(...), _OVERLOAD_ARG4(VA_ARGS, _calc_binary, _calc_unary)(VA_ARGS))

declareImpl2(_calc_binary(out, left, operation, right),
	mvL(left); mvR(right); mv(out, res(operation))
)

declareImpl2(_calc_unary(out, left, operation),
	mvL(left); mv(out, res(operation))
)

declareStub(void, calcAssign(Register out, BinOperation, RegisterSource right))
declareStub(void, calcAssign(Register out, UnarOperation))
declareImpl2(calcAssign(out, ...), calc(out, rd(out), VA_ARGS))

declare(void, combineAssign(Register out, RegisterSource delta),
	(mvL(rd(out)); mvR(0); delta + mv(out, res(add)))
)

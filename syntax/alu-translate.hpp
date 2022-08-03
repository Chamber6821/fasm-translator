#pragma once

#include "registers-translate.hpp"
#include "macro-utils.hpp"

#define mvL(source)  source => (U1 M1)
#define mvR(source) source => (U1 M2)
#define res(operation) (U1 operation)

#define calc(...) _OVERLOAD_ARG4(__VA_ARGS__, _calc_binary, _calc_unary)(__VA_ARGS__)
#define calcAssign(...) _OVERLOAD_ARG4(_, __VA_ARGS__, _calcAssign_binary, _calcAssign_unaty)(__VA_ARGS__)

#define add  G1
#define sub  G2
#define mult G3
#define div  G4
#define mod  G5

#define total   G16
#define single  G17
#define any_one G18

#define combineAssign(out, delta) mvL(rd(out)); mvR(0); delta + mv(out, res(add))

#define _calc_binary(out, left, operation, right) mvL(left); mvR(right); mv(out, res(operation))
#define _calc_unary(out, left, operation) mvL(left); mv(out, res(operation))

#define _calcAssign_binary(out, operation, right) calc(out, rd(out), operation, right)
#define _calcAssign_unaty(out, operation) calc(out, rd(out), operation)

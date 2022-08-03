#pragma once

#include "structures.hpp"
#include "registers.hpp"

enum BinOperation { add, sub, mult, div, mod };
enum UnarOperation { total, single, any_one };

void mvL(RegisterSource);
void mvR(RegisterSource);
Source res(BinOperation operation);
Source res(UnarOperation operation);

void calc(Register out, RegisterSource left, BinOperation, RegisterSource right);
void calc(Register out, RegisterSource left, UnarOperation);
void calcAssign(Register out, BinOperation, RegisterSource right);
void calcAssign(Register out, UnarOperation);

void combineAssign(Register out, RegisterSource delta);

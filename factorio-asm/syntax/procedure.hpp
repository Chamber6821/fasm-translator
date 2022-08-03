#pragma once

#define procedure(name, args, ...) void name args {__VA_ARGS__; return;}

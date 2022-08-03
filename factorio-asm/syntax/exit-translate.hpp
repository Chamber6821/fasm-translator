#pragma once

#include "jump-translate.hpp"

#define exit(statusCode) __exit: S(statusCode) jmp(__exit)

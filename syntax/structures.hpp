#pragma once

struct Source {Source(); Source(int);};
struct RegisterSource : Source {RegisterSource(int number);};

void _isSource(Source);

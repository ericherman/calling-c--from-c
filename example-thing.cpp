// example-thing.cpp: for Calling C++ from C
// SPDX-License-Identifier: CC0-1.0
// Copyright (C) 2024 Eric Herman
// directly inspired by:
// https://nachtimwald.com/2017/08/18/wrapping-c-objects-in-c/

#include <stdlib.h>
#include "example-thing.h"
#include "ExampleThing.hpp"

struct example_thing {
	void *opaque;
};

example_thing_s *example_thing_alloc(int val)
{
	example_thing_s *et;
	et = (example_thing_s *) malloc(sizeof(example_thing_s));
	et->opaque = (void *)new ExampleThing(val);
	return et;
}

void example_thing_free(example_thing_s *et)
{
	if (!et) {
		return;
	}
	delete static_cast<ExampleThing *>(et->opaque);
	free(et);
}

int example_thing_set_val(example_thing_s *et, int val)
{
	ExampleThing *obj = static_cast<ExampleThing *>(et->opaque);
	return obj->setVal(val);
}

int example_thing_get_val(example_thing_s *et)
{
	ExampleThing *obj = static_cast<ExampleThing *>(et->opaque);
	return obj->getVal();
}

int example_thing_do_something(example_thing_s *et)
{
	ExampleThing *obj = static_cast<ExampleThing *>(et->opaque);
	return obj->doSomething();
}

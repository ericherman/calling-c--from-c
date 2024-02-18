// example-thing-test.c: for Calling C++ from C
// SPDX-License-Identifier: CC0-1.0
// Copyright (C) 2024 Eric Herman
// directly inspired by:
// https://nachtimwald.com/2017/08/18/wrapping-c-objects-in-c/

#include <stdio.h>
#include "example-thing.h"

static int check(char *file, int line_number, int actual, int expected)
{
	if (expected == actual) {
		return 0;
	}
	fprintf(stderr, "%s:%d FAIL expected %d but was %d\n",
		file, line_number, expected, actual);
	return 1;
}

#define Check(actual, expected) \
	check(__FILE__, __LINE__, actual, expected)

int main(void)
{
	unsigned errors = 0;

	example_thing_s *et = example_thing_alloc(5);

	errors += Check(example_thing_set_val(et, 23), 5);
	errors += Check(example_thing_get_val(et), 23);

	errors += Check(example_thing_do_something(et), 23);
	errors += Check(example_thing_get_val(et), -24);

	example_thing_free(et);
	et = NULL;

	return errors ? 1 : 0;
}

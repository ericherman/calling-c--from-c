// example-thing.h: for Calling C++ from C
// SPDX-License-Identifier: CC0-1.0
// Copyright (C) 2024 Eric Herman
// directly inspired by:
// https://nachtimwald.com/2017/08/18/wrapping-c-objects-in-c/

#ifndef EXAMPLE_THING_H
#define EXAMPLE_THING_H

#ifdef __cplusplus
extern "C" {
#endif

struct example_thing;
typedef struct example_thing example_thing_s;

example_thing_s *example_thing_alloc(int val);
void example_thing_free(example_thing_s *et);

int example_thing_set_val(example_thing_s *et, int val);
int example_thing_get_val(example_thing_s *et);

int example_thing_do_something(example_thing_s *et);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLE_THING_H */

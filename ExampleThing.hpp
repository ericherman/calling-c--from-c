// ExampleThing.hpp: for Calling C++ from C
// SPDX-License-Identifier: CC0-1.0
// Copyright (C) 2024 Eric Herman
// directly inspired by:
// https://nachtimwald.com/2017/08/18/wrapping-c-objects-in-c/

#ifndef EXAMPLETHING_HPP
#define EXAMPLETHING_HPP

class ExampleThing {
public:
	ExampleThing(int val);

	int setVal(int val);
	int getVal(void);

	int doSomething(void);

private:
	int val;
};

#endif // EXAMPLETHING_HPP

// ExampleThing.cpp: for Calling C++ from C
// SPDX-License-Identifier: CC0-1.0
// Copyright (C) 2024 Eric Herman
// directly inspired by:
// https://nachtimwald.com/2017/08/18/wrapping-c-objects-in-c/

#include "ExampleThing.hpp"

ExampleThing::ExampleThing(int val)
{
	this->val = val;
}

int ExampleThing::setVal(int val)
{
	int was = this->val;
	this->val = val;
	return was;
}

int ExampleThing::getVal(void)
{
	return val;
}

int ExampleThing::doSomething(void)
{
	int was = val;
	val = ~(val);
	return was;
}

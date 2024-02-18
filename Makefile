# Makefile: for Calling C++ from C
# SPDX-License-Identifier: CC0-1.0
# Copyright (C) 2024 Eric Herman
# directly inspired by:
# https://nachtimwald.com/2017/08/18/wrapping-c-objects-in-c/

# $@ : target label
# $< : the first prerequisite after the colon
# $^ : all of the prerequisite files

WCFLAGS=-Wall -Wextra -Werror
CFLAGS=$(WCFLAGS)
CXXFLAGS=$(WCFLAGS)

# VALGRIND ?= $(shell which valgrind)

.PHONY: all
all: check

example-thing.cpp: example-thing.h

ExampleThing.cpp: ExampleThing.hpp

libexamplething.so: example-thing.cpp ExampleThing.cpp
	g++ $(CXXFLAGS) -shared -o $@ $^ -lc

example-thing-test-dynamic: example-thing-test.c libexamplething.so
	gcc $(CFLAGS) -o $@ $< -lexamplething -L.

.PHONY: check-example-thing-test-dynamic
check-example-thing-test-dynamic: example-thing-test-dynamic
	LD_LIBRARY_PATH=. $(VALGRIND) ./$<
	@echo SUCCESS $@

ExampleThing.o: ExampleThing.cpp
	g++ $(CXXFLAGS) -o $@ -c $<

example-thing.o: example-thing.cpp
	g++ $(CXXFLAGS) -o $@ -c $<

libexamplething.a: example-thing.o ExampleThing.o
	ar rcs $@ $^

example-thing-test-static-a: example-thing-test.c libexamplething.a
	gcc $(CFLAGS) -o $@ $^ -lstdc++

.PHONY: check-example-thing-test-static-a
check-example-thing-test-static-a: example-thing-test-static-a
	$(VALGRIND) ./$<
	@echo SUCCESS $@

example-thing-test-static: example-thing-test.c example-thing.o ExampleThing.o
	gcc -o $@ $^ -lstdc++

.PHONY: check-example-thing-test-static
check-example-thing-test-static: example-thing-test-static
	$(VALGRIND) ./$<
	@echo SUCCESS $@

.PHONY: check
check: check-example-thing-test-dynamic \
		check-example-thing-test-static-a \
		check-example-thing-test-static
	@echo SUCCESS $@

.PHONY: clean
clean:
	rm -fv *.o *.a *.so

.PHONY: mrproper
mrproper:
	git clean -dxff

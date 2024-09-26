.PHONY: build run test clean-build

build: clean-build
	mkdir -p build
	git submodule init
	git submodule update
	cd build && cmake .. && make main && make four_tests

run: ./build/main
	./build/main

test: ./build/four_tests
	./build/four_tests

clean-build:
	@rm -rf ./build/

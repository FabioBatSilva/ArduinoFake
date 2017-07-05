default_target: all

all: clean build test clean

cmake:
	@cmake $(CURDIR) -B$(CURDIR)/build

build: cmake
	@cd $(CURDIR)/build && make all

test:
	@cd $(CURDIR)/build && CTEST_OUTPUT_ON_FAILURE=TRUE make test

pio-test:
	@pio test

clean:
	@rm -rf $(CURDIR)/build/*
	@rm -rf $(CURDIR)/.pioenvs/*

.PHONY: cmake build test clean all
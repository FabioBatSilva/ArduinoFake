default_target: all

.PHONY: all
all: clean build deploy test clean

.PHONY: cmake
cmake:
	@cmake $(CURDIR) -B$(CURDIR)/build

.PHONY: build
build: cmake
	@cd $(CURDIR)/build && make all

.PHONY: test
test:
	@cd $(CURDIR)/build && CTEST_OUTPUT_ON_FAILURE=TRUE make test

.PHONY: pio-test
pio-test:
	@pio test

.PHONY: cmake-test
cmake-test: build test

.PHONY: clean
clean:
	@rm -rf $(CURDIR)/build/*
	@rm -rf $(CURDIR)/.pioenvs/*
	@rm -rf $(CURDIR)/.pio/*

.PHONY: deploy
deploy:
	cp $(CURDIR)/external/fakeit/fakeit-repo/single_header/standalone/* $(CURDIR)/src


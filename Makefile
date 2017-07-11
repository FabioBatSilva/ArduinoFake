default_target: all

.PHONY: all
all: clean build test clean

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

.PHONY: pio-test-examples
pio-test-examples: clean
	@for i in `ls -d $(CURDIR)/examples/*`; do \
		echo "Testing $$i"; \
        cd $$i; \
        pio test; \
    done

.PHONY: clean
clean:
	@rm -rf $(CURDIR)/build/*
	@rm -rf $(CURDIR)/.pioenvs/*
	@rm -rf $(CURDIR)/examples/**/.pioenvs/*

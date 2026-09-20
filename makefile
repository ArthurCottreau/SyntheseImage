CC := g++

# Application directories
SOURCEDIR := source/
INCLUDEDIR := include/

CFLAGS := -I $(INCLUDEDIR)
LDFLAGS := -lCatch2Main -lCatch2

SOURCES := $(wildcard $(SOURCEDIR)/*.cpp) # Retrieves all .cpp files
TEST_SOURCES := source/tests/unit_tests.cpp source/vecteur.cpp
TARGET := main # Executable name

# Rules get executed even if files of those names exist
.PHONY: all build

# First rule is the default so 'make all' and 'make build' are identical
all: unit_tests build

unit_tests:
	mkdir -p $@
	$(CC) $(TEST_SOURCES) -o $@/$(TARGET) $(CFLAGS) $(LDFLAGS)
	./$@/main

build:
	mkdir -p $@
	$(CC) $(SOURCES) -o $@/$(TARGET) $(CFLAGS)

clean:
	rm -r unit_tests build

CC := g++

# Application directories
SOURCEDIR := source/
INCLUDEDIR := include/

CFLAGS := -I $(INCLUDEDIR) -O
LDFLAGS := -lCatch2Main -lCatch2

SOURCES := $(wildcard $(SOURCEDIR)/*.cpp) # Retrieves all .cpp files
TEST_SOURCES := source/tests/unit_tests.cpp source/vecteur.cpp
TARGET := main # Executable name

COLOUR_GREEN := \033[0;32m
END_COLOUR := \033[0m

# Rules get executed even if files of those names exist
.PHONY: all unit_tests benchmark build clean

# First rule is the default
all: unit_tests benchmark build

unit_tests:
	mkdir -p $@
	$(CC) $(TEST_SOURCES) -o $@/$(TARGET) $(CFLAGS) $(LDFLAGS)
	./$@/main

benchmark:
	mkdir -p $@
	$(CC) $(SOURCES) -o $@/$(TARGET) $(CFLAGS) -pg
	cd $@; { time ./$(TARGET); } 2> time.txt
	cd $@; gprof $(TARGET) gmon.out > $@.txt # Creates benchmark data

	@echo -e "$(COLOUR_GREEN)"
	@xargs echo < $@/time.txt # Reads out time it takes to run app
	@echo -e "$(END_COLOUR)"

build:
	mkdir -p $@
	$(CC) $(SOURCES) -o $@/$(TARGET) $(CFLAGS) -flto # With LTO

clean:
	rm -r -f unit_tests benchmark build

CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c99 -g
CXXFLAGS = -Wall -Wextra -std=c++14 -g

# Check if gtest is installed (common locations)
# GTEST_DIR = /usr/src/googletest
GTEST_DIR = /usr/lib/x86_64-linux-gnu
GTEST_LOCAL = ./googletest

# For linking tests (need C++ for gtest)
TEST_CXXFLAGS = $(CXXFLAGS) -pthread
TEST_LDFLAGS = -pthread

all: testable_code

testable_code: main.c testable_code.c
	$(CC) $(CFLAGS) -o testable_code main.c testable_code.c

clean:
	rm -f testable_code test_suite

# Test target - builds and runs tests
test: test_suite
	./test_suite

# Build test executable
test_suite: testable_code.c test.cpp $(GTEST_DIR)/libgtest.a $(GTEST_DIR)/libgtest_main.a
	$(CXX) $(TEST_CXXFLAGS) -I$(GTEST_DIR)/include -I. testable_code.c test.cpp -o test_suite $(GTEST_DIR)/libgtest.a $(GTEST_DIR)/libgtest_main.a $(TEST_LDFLAGS)

# Fallback if gtest is not installed system-wide
$(GTEST_DIR)/libgtest.a $(GTEST_DIR)/libgtest_main.a:
	@echo "Google Test not found at $(GTEST_DIR)"
	@echo "You can install it via:"
	@echo "  sudo apt-get install libgtest-dev cmake  # Debian/Ubuntu"
	@echo "  brew install googletest                   # macOS"
	@echo "Or clone and build from https://github.com/google/googletest"
	@exit 1

.PHONY: all clean test

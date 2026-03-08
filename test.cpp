#include "testable_code.h"
#include <gtest/gtest.h>

#include <string>

// Helper to capture output for test assertions

class OutputCapture {
private:
    FILE* original_stdout;
    char buffer[8192];
    int buffer_pos = 0;

public:
    OutputCapture() {
        original_stdout = stdout;
        setvbuf(original_stdout, buffer, _IOFBF, sizeof(buffer));
    }
    
    ~OutputCapture() {
        // Empty destructor - we'll access output after destructor in test
    }
    
    char* get_test_output() {
        return buffer;
    }
};

TEST(PrintProgramInfoTest, NoArguments) {
    OutputCapture capture;
    
    char *argv[] = { (char*)"test_program", nullptr };
    print_program_info(1, argv);
    
    EXPECT_NE(strstr(capture.get_test_output(), "Program name: test_program"), nullptr);
    EXPECT_NE(strstr(capture.get_test_output(), "No arguments provided."), nullptr);
}

TEST(PrintProgramInfoTest, WithArguments) {
    OutputCapture capture;
    
    char *argv[] = { (char*)"test_program", (char*)"arg1", (char*)"arg2", nullptr };
    print_program_info(3, argv);
    
    EXPECT_NE(strstr(capture.get_test_output(), "Program name: test_program"), nullptr);
    EXPECT_NE(strstr(capture.get_test_output(), "1: arg1"), nullptr);
    EXPECT_NE(strstr(capture.get_test_output(), "2: arg2"), nullptr);
}

#include <stdio.h>
#include "testable_code.h"

void print_program_info(int argc, char *argv[]) {
    printf("Program name: %s\n", argv[0]);
    
    if (argc > 1) {
        printf("Arguments:\n");
        for (int i = 1; i < argc; i++) {
            printf("  %d: %s\n", i, argv[i]);
        }
    } else {
        printf("No arguments provided.\n");
    }
}
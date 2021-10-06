//
// Created by ivanbrekman on 06.10.2021.
//

#ifndef SIMPLEPROCESSOR_PROCESSOR_H
#define SIMPLEPROCESSOR_PROCESSOR_H

#include "libs/stack.h"

enum commands {
    PUSH   =  1,
    POP    =  2,

    ADD    =  3,
    SUB    =  4,
    MUL    =  5,

    VERIFY =  6,
    DUMP   =  7,
    PRINT  =  8,
    HLT    = -1,
};

enum exit_codes {
    BREAK = -1
};

char* exit_code_desc(int exit_code);

Text* get_commands(Text* data);

int     command_type(const char* command);
int analyze_commands(const Text* commands, size_t size);
int execute_commands(const Text* commands, size_t size, Stack* stack);

#endif //SIMPLEPROCESSOR_PROCESSOR_H

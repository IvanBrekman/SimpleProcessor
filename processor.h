//
// Created by ivanbrekman on 06.10.2021.
//

#ifndef SIMPLEPROCESSOR_PROCESSOR_H
#define SIMPLEPROCESSOR_PROCESSOR_H

#include "libs/stack.h"


enum exit_codes {
    BREAK = -1
};

char* exit_code_desc(int exit_code);

int     command_type(const char* command);
int analyze_commands(const Text* commands, size_t size);
int execute_commands(const Text* commands, size_t size, Stack* stack);

#endif //SIMPLEPROCESSOR_PROCESSOR_H

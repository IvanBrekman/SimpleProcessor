//
// Created by ivanbrekman on 09.10.2021.
//

#ifndef SIMPLEPROCESSOR_COMPILER_H
#define SIMPLEPROCESSOR_COMPILER_H

#include "libs/stack.h"

enum exit_codes {
    BREAK = -1
};

char* exit_code_desc(int exit_code);

Text* get_tcom(Text* data);

int     command_type(const char* command);
int analyze_commands(const Text* commands, size_t size);

#endif //SIMPLEPROCESSOR_COMPILER_H

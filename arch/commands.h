//
// Created by ivanbrekman on 16.10.2021.
//

#ifndef SIMPLEPROCESSOR_COMMANDS_H
#define SIMPLEPROCESSOR_COMMANDS_H

#include "../libs/stack.h"

#include "helper.h"
#include "registers.h"

struct Processor {
    Stack stack = {};
    int ip      = -1; // instruction pointer

    Registers regs    = { }; // regs names: ax, bx, cx, dx
    int RAM[RAM_SIZE] = { 0 };
};

struct CommandParameters {
    const char* name;
    int code;

    int argc;
    int arg_types[MAX_ARGV];

    int (*execute_func) (int argc, int* argv);
};

int init_processor();
int stack_state(FILE* log=stdout);

#define COMMAND_DEFINITION(name, code, argc_m, argv_m, func, body) int func(int argc, int* argv);
    #include "commands_definition.h"
#undef COMMAND_DEFINITION

#define COMMAND_DEFINITION(name, code, argc, argv, func, body) { name, code, argc, argv, func },
const CommandParameters ALL_COMMANDS[] {
    #include "commands_definition.h"
};
#undef COMMAND_DEFINITION

const int UNKNOWN = -1;

#endif //SIMPLEPROCESSOR_COMMANDS_H

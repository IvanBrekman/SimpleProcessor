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
    int RAM[RAM_SIZE] = { 0, 0, 0, 0, 0, 0 };
};

struct CommandParameters {
    const char* name = "";
    int code = -1;

    int argc_min  =  0;
    int argc_max  = -1;
    int args_type =  0;

    int (*execute_func) (int args_type, int* argv);
};

int    init_processor();
int destroy_processor();

int stack_state(FILE* log=stdout);
int regs_state();

#define COMMAND_DEFINITION(name, code, argc_min, argc_max, argv_m, func, body) int func(int args_type, int* argv);
    #include "commands_definition.h"
#undef COMMAND_DEFINITION

#define COMMAND_DEFINITION(name, code, argc_min, argc_max, argv, func, body) { name, code, argc_min, argc_max, argv, func },
const CommandParameters ALL_COMMANDS[] {
    #include "commands_definition.h"
};
#undef COMMAND_DEFINITION

const int UNKNOWN = -1;

#endif //SIMPLEPROCESSOR_COMMANDS_H

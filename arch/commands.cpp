//
// Created by ivanbrekman on 16.10.2021.
//

#include <malloc.h>

#include "../libs/baselib.h"
#include "../libs/stack.h"
#include "helper.h"

Stack st = {};

int init_stack() {
    stack_ctor(st);

    return Stack_error(&st);
}
int stack_state(FILE* log) {
    print_stack_line(&st, ", ", "\n", log);

    return exit_codes::OK;
}

#define COMMAND_DEFINITION(name, code, argc_m, argv_m, func, body) int func(int argc, int* argv) body
    #include "commands_definition.h"
#undef COMMAND_DEFINITION

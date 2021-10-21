//
// Created by ivanbrekman on 16.10.2021.
//

#include <malloc.h>

#include "../libs/baselib.h"
#include "../libs/stack.h"

#include "helper.h"
#include "commands.h"

Processor processor = {};

int init_processor() {
    stack_ctor(processor.stack);

    init_registers(&processor.regs, REG_NAMES);

    return Stack_error(&processor.stack);
}
int stack_state(FILE* log) {
    print_stack_line(&processor.stack, ", ", "\n", log);

    return exit_codes::OK;
}

#define COMMAND_DEFINITION(name, code, argc_m, argv_m, func, body) int func(int argc, int* argv) body
    #include "commands_definition.h"
#undef COMMAND_DEFINITION

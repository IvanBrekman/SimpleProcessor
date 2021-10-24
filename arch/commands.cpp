//
// Created by ivanbrekman on 16.10.2021.
//

#include <malloc.h>

#include "../libs/baselib.h"
#include "../libs/stack.h"

#include "helper.h"
#include "commands.h"

Processor processor = { };

Processor* init_processor() {
    processor.ip = 0;

    stack_ctor(processor.stack);
    registers_ctor(&processor.regs, REG_NAMES);

    return &processor;
}
int     destroy_processor() {
    processor.ip = -1;

    Stack_dtor_(&processor.stack);
    registers_dtor(&processor.regs);

    return 0;
}

int stack_state(FILE* log) {
    print_stack_line(&processor.stack, ", ", "\n", log);

    return exit_codes::OK;
}
int regs_state() {
    print_reg(&processor.regs);

    return exit_codes::OK;
}

int get_processor_ip() {
    getchar();
    getchar();
    while(getchar() != '\n');
    return processor.ip;
}
int set_processor_ip(int value) {
    processor.ip += value;
    return processor.ip;
}

#define COMMAND_DEFINITION(name, code, argc_min, argc_max, argv_m, func, body) int func(int args_type, int* argv) body
    #include "commands_definition.h"
#undef COMMAND_DEFINITION

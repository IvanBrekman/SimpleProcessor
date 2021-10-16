//
// Created by ivanbrekman on 16.10.2021.
//

#include <malloc.h>
#include "../config.h"

#include "../libs/baselib.h"
#include "../libs/stack.h"
#include "helper.h"

Stack st = {};

int init_stack() {
    stack_ctor(st);

    return Stack_error(&st);
}

int execute_hlt(int argc, int* argv) {
    return BREAK;
}

int execute_push(int argc, int* argv) {
    push(&st, argv[0]);

    return OK;
}
int execute_pop(int argc, int* argv) {
    pop(&st);

    return OK;
}

int execute_add(int argc, int* argv) {
    push(&st, pop(&st) + pop(&st));

    return OK;
}
int execute_sub(int argc, int* argv) {
    push(&st, -pop(&st) + pop(&st));

    return OK;
}
int execute_mul(int argc, int* argv) {
    push(&st, pop(&st) * pop(&st));

    return OK;
}

int execute_verify(int argc, int* argv) {
    int err = Stack_error(&st);
    printf("Stack Verify: %s (%d)\n", Stack_error_desc(err), err);

    return OK;
}
int execute_dump(int argc, int* argv) {
    stack_dump(st, "System dump call");

    return OK;
}
int execute_print(int argc, int* argv) {
    print_stack(&st);

    return OK;
}

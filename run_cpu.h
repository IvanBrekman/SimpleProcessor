//
// Created by ivanbrekman on 17.10.2021.
//

#ifndef SIMPLEPROCESSOR_RUN_CPU_H
#define SIMPLEPROCESSOR_RUN_CPU_H

#include "libs/baselib.h"
#include "libs/file_funcs.h"

#define CHECK_SYSTEM_CALL(system_call, source_file, executable_file) { \
    if (file_last_change(source_file) > file_last_change(executable_file)) { \
        system_call;                                                        \
    } else {                                                           \
        printf("Skip system call \"%s\"\n", #system_call);\
    }                                                            \
}

static const char* compile_strings[] = {
        "gcc asm/asm.cpp libs/baselib.cpp libs/file_funcs.cpp libs/stack.cpp arch/helper.cpp arch/commands.cpp -lm -o asm/asm.cat",
        "gcc dis/dis.cpp libs/baselib.cpp libs/file_funcs.cpp libs/stack.cpp arch/helper.cpp arch/commands.cpp -lm -o dis/dis.cat",
        "gcc CPU/cpu.cpp libs/baselib.cpp libs/file_funcs.cpp libs/stack.cpp arch/helper.cpp arch/commands.cpp -lm -o CPU/cpu.cat"
};
static const char* execute_strings[] = {
        "./asm/asm.cat ",
        "./dis/dis.cat ",
        "./CPU/cpu.cat "
};

int run_cpu(const char* source_file, const char* executable_file);

#endif //SIMPLEPROCESSOR_RUN_CPU_H

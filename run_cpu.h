//
// Created by ivanbrekman on 17.10.2021.
//

#ifndef SIMPLEPROCESSOR_RUN_CPU_H
#define SIMPLEPROCESSOR_RUN_CPU_H

#include "libs/baselib.h"
#include "libs/file_funcs.h"

static const char* TRACKED_PROGRAMS[] = {
        "arch/commands.cpp", "arch/commands.h",
        "arch/helper.cpp",   "arch/helper.h",
        "arch/commands_definition.h",

        "asm/asm.cpp", "asm/asm.h",
        "dis/dis.cpp", "dis/dis.h",
        "CPU/cpu.cpp", "CPU/cpu.h",

        "libs/baselib.cpp",    "libs/baselib.h",
        "libs/file_funcs.cpp", "libs/file_funcs.h",
        "libs/stack.cpp",      "libs/stack.h",

        "config.h"
};

#define CHECK_TRACKED_PROGRAMS(system_call, executable_file) { \
    for (const char* tracked_program : TRACKED_PROGRAMS) {                                        \
        if (file_last_change(tracked_program) > file_last_change(executable_file)) {        \
            int exit_code = system_call;                                                    \
            if (exit_code != 0) {                                                           \
                printf("%s\n" RED "program finished with exit code %d" NATURAL "\n", #system_call, exit_code);        \
                assert(0 && "Bad exit code");                                               \
            }                                                       \
        updated = 1; \
        break;                                                                          \
        }                                                                                   \
    }                                                                \
}
#define CHECK_PROCESSOR_SYSTEM_CALL(system_call, executable_file) { \
    int updated = 0;\
    CHECK_TRACKED_PROGRAMS(system_call, executable_file);                                                                                    \
    if (!updated) printf(BLUE "Skip processor system call \"%s\"" NATURAL "\n", #system_call);                            \
}

#define CHECK_SYSTEM_CALL(system_call, source_file, executable_file) { \
    int updated = 0;\
    CHECK_TRACKED_PROGRAMS(system_call, executable_file);                                                                                    \
    if (file_last_change(source_file) > file_last_change(executable_file)) {                      \
        int exit_code = system_call;                                                    \
        if (exit_code != 0) {                                                           \
            printf(RED "program finished with exit code %d" NATURAL "\n", exit_code);        \
            assert(0 && "Bad exit code");                                               \
        }                                                       \
        updated = 1;                                                                   \
    }                                                                  \
    if (!updated) printf(ORANGE "Skip system call \"%s\"" NATURAL "\n", #system_call);                            \
}

static const char* decompile_output = "commands_disassembled.txt";
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

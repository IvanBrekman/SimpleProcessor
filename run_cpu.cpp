//
// Created by ivanbrekman on 17.10.2021.
//

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "libs/baselib.h"
#include "run_cpu.h"

int run_cpu(const char* source_file, const char* executable_file) {
    system("cd /home/ivanbrekman/CLionProjects/SimpleProcessor");
    system("dir");

    char* command_compile   = (char*) calloc(strlen(execute_strings[0]) + strlen(source_file) + 1 + strlen(executable_file) + 1, sizeof(char));
    strcpy(command_compile, execute_strings[0]);
    strcat(command_compile, source_file);
    strcat(command_compile, " ");
    strcat(command_compile, executable_file);
    printf("compile command:   %s\n", command_compile);

    char* command_decompile = (char*) calloc(strlen(execute_strings[1]) + strlen(executable_file) + 1 + strlen(decompile_output) + 1, sizeof(char));
    strcpy(command_decompile, execute_strings[1]);
    strcat(command_decompile, executable_file);
    strcat(command_decompile, " ");
    strcat(command_decompile, decompile_output);
    printf("decompile command: %s\n", command_decompile);

    char* command_execute   = (char*) calloc(strlen(execute_strings[2]) + strlen(source_file) + 1, sizeof(char));
    strcpy(command_execute, execute_strings[2]);
    strcat(command_execute, executable_file);
    printf("execute command:   %s\n", command_execute);

    printf(BLUE "text\n" NATURAL);
    CHECK_SYSTEM_CALL(system(compile_strings[0]), "asm/asm.cpp", "asm/asm.cat");
    CHECK_SYSTEM_CALL(system(compile_strings[1]), "dis/dis.cpp", "dis/dis.cat");
    CHECK_SYSTEM_CALL(system(compile_strings[2]), "CPU/cpu.cpp", "CPU/cpu.cat");

    CHECK_SYSTEM_CALL(system(command_compile),   source_file, executable_file);
    CHECK_SYSTEM_CALL(system(command_decompile), source_file, decompile_output);
    //printf(RED "text\n" NATURAL);

    system(command_execute);

    return 1;
}

//
// Created by ivanbrekman on 04.10.2021.
//

#include <cstdio>
#include <cstdlib>
#include <climits>

#include "run_cpu.h"
#include "libs/file_funcs.h"

// gcc main.cpp run_cpu.cpp libs/baselib.cpp libs/file_funcs.cpp -o main.out
int main(int argc, char** argv) {
    char* source_file     = (char*) calloc(50, sizeof(char));
    char* executable_file = (char*) calloc(50, sizeof(char));

    if (argc >= 3) {
        source_file     = argv[1];
        executable_file = argv[2];
    } else {
        printf("    config.h last change: %ld\n"
               "file_funcs.h last change: %ld\n"
               "max long value          : %ld\n",
               file_last_change("../config.h"), file_last_change("../libs/file_funcs.h"), LONG_MAX);
        printf("Введите путь к исходному файлу\n");
        scanf("%s", source_file);

        printf("Введите путь к исполняемому файлу (в который запишутся команды)\n");
        scanf("%s",executable_file);
    }

    int exit_code = run_cpu(source_file, executable_file);

    return exit_code;
}

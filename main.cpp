//
// Created by ivanbrekman on 04.10.2021.
//

#include <cstdio>
#include <cstdlib>

#include "run_cpu.h"

int main(int argc, char** argv) {
    char* source_file     = (char*) calloc(50, sizeof(char));
    char* executable_file = (char*) calloc(50, sizeof(char));

    if (argc >= 3) {
        source_file     = argv[1];
        executable_file = argv[2];
    } else {
        printf("Введите путь к исходному файлу\n");
        scanf("%s", source_file);

        printf("Введите путь к исполняемому файлу (в который запишутся команды)\n");
        scanf("%s",executable_file);
    }

    int exit_code = run_cpu(source_file, executable_file);

    return exit_code;
}

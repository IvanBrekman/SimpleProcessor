//
// Created by ivanbrekman on 04.10.2021.
//

#include "config.h"

#include <cstdio>

#include "libs/stack.h"
#include "libs/file_funcs.h"

#include "processor.h"

int main(int argc, char** argv) {
    Stack st = {};
    stack_ctor(st);

    print_stack(&st);
    printf("\n");

    Text str_commands = get_text_from_file("../commands.txt");

    int n_commands = (int)str_commands.lines;
    Text* commands = get_commands(&str_commands);

    printf("All commands:\n");
    for (int i = 0; i < n_commands; i++) {
        print_text(&commands[i], ", ");
    }

    int cmd_analyzer = analyze_commands(commands, n_commands);
    if (cmd_analyzer) {
        int exit_code = execute_commands(commands, n_commands, &st);

        if (exit_code != 0) {
            printf(RED "Program falls with exit code %d (%s)" NATURAL, exit_code, exit_code_desc(exit_code));
        } else {
            printf(BLUE "Program finished with exit code 0" NATURAL);
        }
    } else {
        printf(RED "Incorrect commands detected!\n" NATURAL);
    }

    return 0;
}

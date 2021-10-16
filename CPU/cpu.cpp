//
// Created by ivanbrekman on 15.10.2021.
//

#include "../arch/helper.h"
#include "cpu.h"
#include "../arch/commands.h"
#include "../libs/baselib.h"

int execute(const char* execute_file) {
    init_stack();

    int n_commands = -1;
    BinCommand* mcodes = read_mcodes(execute_file, &n_commands);

    execute_commands(mcodes, n_commands);

    return 1;
}

int execute_commands(BinCommand* mcodes, int n_commands) {
    for (int i = 0; i < n_commands; i++) {
        BinCommand b_command = mcodes[i];
        CommandParameters command = ALL_COMMANDS[b_command.sgn.cmd];

        int exit_code = command.execute_func((int)b_command.sgn.argc, b_command.argv);

        if (exit_code != 0) {
            printf(RED "Program aborted with exit code %d\n" NATURAL, exit_code);
            assert(0 && "Intentional abort");
        }
    }

    return 1;
}

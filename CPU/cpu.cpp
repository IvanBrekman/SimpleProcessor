//
// Created by ivanbrekman on 15.10.2021.
//

#include "../libs/baselib.h"

#include "../arch/helper.h"
#include "../arch/commands.h"

#include "cpu.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf(RED "Cant parse executable file path\n" NATURAL);
        return INVALID_SYNTAX;
    }

    execute(argv[1]);
}

int execute(const char* execute_file) {
    init_stack();

    int n_commands = -1;
    BinCommand* mcodes = read_mcodes(execute_file, &n_commands);

    execute_commands(mcodes, n_commands);

    return 0;
}

int execute_commands(BinCommand* mcodes, int n_commands) {
    for (int i = 0; i < n_commands; i++) {
        BinCommand b_command = mcodes[i];
        CommandParameters command = ALL_COMMANDS[b_command.sgn.cmd];

        int exit_code = command.execute_func((int)b_command.sgn.argc, b_command.argv);

        if (exit_code != 0) {
            switch (exit_code)
            {
            case exit_codes::BREAK:
                printf(RED "Program aborted with exit code %d\n" NATURAL, exit_code);
                assert(0 && "Intentional abort");break;
            case exit_codes::EXIT:
                return 0;
            default:
                break;
            }
        }
    }

    return 0;
}

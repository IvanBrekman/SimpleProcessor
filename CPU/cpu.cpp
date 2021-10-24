//
// Created by ivanbrekman on 15.10.2021.
//

#include <cerrno>

#include "../libs/baselib.h"
#include "../libs/file_funcs.h"

#include "../arch/helper.h"
#include "../arch/commands.h"

#include "cpu.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf(RED "Cant parse executable file path\n" NATURAL);
        return INVALID_SYNTAX;
    }

    LOG(printf("------start executing------\n"););
    int exit_code = execute(argv[1]);
    LOG(printf("------end   executing------\n\n"););

    return exit_code;
}

int execute(const char* execute_file) {
    init_processor();

    int n_commands = -1;
    errno = 0;
    BinCommand* mcodes = read_mcodes(execute_file, &n_commands);
    if (errno != 0) {
        printf(RED "%s\n" NATURAL, error_desc(errno));
        return exit_codes::INVALID_SYNTAX;
    }

    int exit_code = execute_commands(mcodes, n_commands);
    return exit_code;
}

int execute_commands(BinCommand* mcodes, int n_commands) {
    printf("Executing commands:\n");

    for (int i = 0; i < n_commands; i++) {
        BinCommand b_command = mcodes[i];
        CommandParameters command = ALL_COMMANDS[b_command.sgn.cmd];
        int com_size = sizeof(ALL_COMMANDS) / sizeof(ALL_COMMANDS[0]);

        if (b_command.sgn.cmd < 0 || b_command.sgn.cmd >= com_size) {
            printf(RED "Incorrect command code (%d)\n" NATURAL, b_command.sgn.cmd);
            return exit_codes::INVALID_SYNTAX;
        }

        LOG(if (LOG_STACK_STATE == 1) {
                printf("\n");
                printf("Stack:  ");
                stack_state();
            }
            print_command(&b_command, i);
        );
        int exit_code = command.execute_func((int)b_command.args_type, b_command.argv);

        if (exit_code != exit_codes::OK) {
            switch (exit_code)
            {
            case exit_codes::BREAK:
                printf(RED "Program aborted with exit code %d\n" NATURAL, exit_code);
                assert(0 && "Intentional abort");break;
            case exit_codes::EXIT:
                return exit_codes::OK;
            default:
                break;
            }
        }
    }
    LOG(printf("\nStack final state:\n");
        stack_state();
        printf("registers state\n");
        regs_state();
    );

    return exit_codes::NO_OBVIOUS_END;
}

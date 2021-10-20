//
// Created by ivanbrekman on 15.10.2021.
//

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#include "../libs/baselib.h"
#include "../libs/file_funcs.h"

#include "../arch/helper.h"
#include "../arch/commands.h"
#include "asm.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        printf(RED "Cant parse source file path or executable file path\n" NATURAL);
        return INVALID_SYNTAX;
    }

    LOG(printf("------start assembly------\n"););
    int exit_code = assembly(argv[1], argv[2]);
    LOG(printf("------end   assembly------\n\n"););

    return exit_code;
}

int assembly(const char* source_file, const char* executable_file) {
    assert(VALID_PTR(source_file)     && "Incorrect source_file ptr");
    assert(VALID_PTR(executable_file) && "Incorrect executable_file ptr");

    Text text = get_text_from_file(source_file);

    int      n_commands = (int)text.lines;
    Text* text_commands = get_tcom(&text);

    LOG(printf("All commands (asm):\n");
        for (int i = 0; i < n_commands; i++) {
            print_text(&text_commands[i], ", ");
        }
        printf("\n");
    );

    errno = 0;
    Text wrong_command = check_tcom(text_commands, n_commands);
    if (errno != 0) {
        printf(RED "Incorrect command \"");
        print_text(&wrong_command, ", ", "");
        printf("\"\n%s\n" NATURAL, error_desc(errno));

        return exit_codes::INVALID_SYNTAX;
    }

    BinCommand* mcodes = get_mcodes_from_tcom(text_commands, n_commands);
    LOG(print_commands(mcodes, n_commands););

    write_mcodes(mcodes, n_commands, executable_file);

    FREE_PTR(text_commands, Text);
    FREE_PTR(mcodes, BinCommand);
    return exit_codes::OK;
}

Text*       get_tcom(const Text* data) {
    assert(VALID_PTR(data) && "Invalid data ptr");

    Text* commands = (Text*)calloc(data->lines, sizeof(Text));

    for (int i = 0; i < data->lines; i++) {
        char* str_command = data->text[i].ptr;

        int args = replace(str_command, data->text[i].len, ' ', '\0') + 1;
        Text command = {
                str_command,
                data->text[i].len + 1,
                (String*)calloc(args, sizeof(String)),
                (size_t)args
        };
        load_string_pointers(&command);

        commands[i] = command;
    }

    return commands;
}
Text        check_tcom(const Text* tcom, int n_commands) {
    for (int i = 0; i < n_commands; i++) {
        Text cmd = tcom[i];

        int cmd_code = command_type((const char*)cmd.text[0].ptr);
        if (cmd_code == UNKNOWN) {
            errno = UNKNOWN_COMMAND;
            return cmd;
        }

        if ((cmd.lines - 1) != ALL_COMMANDS[cmd_code].argc) {
            errno = INCORRECT_ARG_AMOUNT;
            return cmd;
        }

        for (int arg = 1; arg < cmd.lines; arg++) {
            if (is_number(cmd.text[arg].ptr)) {
                if (extract_bit(ALL_COMMANDS[cmd_code].arg_types[arg - 1], 0) == 0) { // if num is not allowed type
                    errno = INCORRECT_ARG_TYPE;
                    return cmd;
                }
            } else {
                if (extract_bit(ALL_COMMANDS[cmd_code].arg_types[arg - 1], 1) == 0) { // if register is not allowed type
                    errno = INCORRECT_ARG_TYPE;
                    return cmd;
                }
            }
        }
    }

    return tcom[0];
}
BinCommand* get_mcodes_from_tcom(const Text* commands, int n_commands) {
    BinCommand* bit_cmd = (BinCommand*)calloc(n_commands, sizeof(BinCommand));

    for (int i = 0; i < n_commands; i++) {
        Text text_cmd = commands[i];
        BinCommand cmd = {};
        cmd.sgn = { (unsigned)text_cmd.lines - 1, (unsigned)command_type(text_cmd.text[0].ptr) };
        for (int arg = 1; arg < text_cmd.lines; arg++) {
            cmd.argv[arg - 1] = atoi(text_cmd.text[arg].ptr);
        }

        bit_cmd[i] = cmd;
    }

    return bit_cmd;
}

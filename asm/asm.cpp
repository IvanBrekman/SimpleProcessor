//
// Created by ivanbrekman on 15.10.2021.
//

#include <cassert>
#include <cstdlib>
#include <cstring>

#include "../libs/baselib.h"
#include "../libs/file_funcs.h"

#include "../helper.h"
#include "asm.h"

int assembly(const char* source_file, const char* executable_file) {
    assert(VALID_PTR(source_file,     char) && "Incorrect source_file ptr");
    assert(VALID_PTR(executable_file, char) && "Incorrect executable_file ptr");

    Text text = get_text_from_file(source_file);

    int      n_commands = (int)text.lines;
    Text* text_commands = get_tcom(&text);

    printf("All commands:\n");
    for (int i = 0; i < n_commands; i++) {
        print_text(&text_commands[i], ", ");
    }

    Command* mcodes = get_mcodes_from_tcom(text_commands, n_commands);
    print_commands(mcodes, n_commands);

    write_mcodes(mcodes, n_commands, executable_file);

    printf("-------------------------\n\n");
    int n_com = -1;
    Command* cmd = read_mcodes(executable_file, &n_com);

    printf("commands num: %d\n", n_com);
    print_commands(cmd, n_com);

    printf("-------------------------\n\n");

    FREE_PTR(text_commands, Text);
    FREE_PTR(mcodes, Command);
    return 1;
}

Text* get_tcom(const Text* data) {
    assert(VALID_PTR(data, Text) && "Invalid data ptr");

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
Command* get_mcodes_from_tcom(const Text* commands, int n_commands) {
    Command* bit_cmd = (Command*)calloc(n_commands, sizeof(Command));

    for (int i = 0; i < n_commands; i++) {
        Text text_cmd = commands[i];
        Command cmd = {};
        cmd.sgn = { (unsigned)text_cmd.lines - 1, (unsigned)command_type(text_cmd.text[0].ptr) };
        for (int arg = 1; arg < text_cmd.lines; arg++) {
            cmd.argv[arg - 1] = atoi(text_cmd.text[arg].ptr);
        }

        bit_cmd[i] = cmd;
    }

    return bit_cmd;
}

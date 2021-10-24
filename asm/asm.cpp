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

    // int arguments[] = { -1, -1, -1, -1 };
    // printf("parse: %d\n", parse_arg("[dx+1]", arguments));
    // for(int i = 0; i < 4; i++) {
    //     printf("%d ", arguments[i]);
    // }
    // printf("\n");

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
    LOG(printf("Check_tcom result: %d\n", errno););
    if (errno != 0) {
        int err = errno;
        printf(RED "Incorrect command '");
        print_text(&wrong_command, ", ", "");
        printf("'\n%s\n" NATURAL, error_desc(err));

        return exit_codes::INVALID_SYNTAX;
    }

    LOG(printf("Assembled commands:\n"););
    BinCommand* mcodes = get_mcodes_from_tcom(text_commands, n_commands);

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
            errno = compile_errors::UNKNOWN_COMMAND;
            return cmd;
        }

        if ((cmd.lines - 1) < ALL_COMMANDS[cmd_code].argc_min || (cmd.lines - 1) > ALL_COMMANDS[cmd_code].argc_max) {
            errno = compile_errors::INCORRECT_ARG_AMOUNT;
            return cmd;
        }

        for (int arg = 1; arg < cmd.lines; arg++) {
            int res_types = parse_arg(cmd.text[arg].ptr);
            LOG(printf("parse_arg result: %d\n\n", res_types););
            if (res_types == -1 || !extract_bit(ALL_COMMANDS[cmd_code].args_type, res_types)) {
                errno = compile_errors::INCORRECT_ARG_TYPE;
                return cmd;
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
            int real_argc = 0;
            int arg_type  = parse_arg(text_cmd.text[arg].ptr, cmd.argv, &real_argc);
            cmd.args_type = arg_type;
            cmd.sgn.argc  = real_argc;
        }

        bit_cmd[i] = cmd;

        LOG(print_command(&cmd, i););
    }

    return bit_cmd;
}

int parse_arg(const char* arg, int* argv, int* real_argc) {
    char      name[MAX_ARG_SIZE] = { };
    char const_val[MAX_ARG_SIZE] = { };

    Registers reg_tmp = {};
    init_registers(&reg_tmp, REG_NAMES);
    
    int cond    = arg[0] == '[';
    int arg_len = strlen(arg) - 2 * cond;
    int is_ram  = cond << 2;
    arg = arg + cond;

    int parse_len = 0;
    int argc = sscanf(arg, "%[a-z]+%[0-9]%n", name, const_val, &parse_len);
    LOG(printf( "[a-z]+[0-9]\n"
                "sscanf res : %d\n"
                "name       : \"%s\"\n"
                "const_value: \"%s\"\n"
                "parse len  : %d\n"
                "arg len    : %d\n\n",
                argc, name, const_val, parse_len, arg_len);
    );
    if (argc == 2 && get_reg_by_name(&reg_tmp, name) != -1 && parse_len == arg_len) {
        if (VALID_PTR(argv)) {
            argv[0] = get_reg_by_name(&reg_tmp, name);
            argv[1] = atoi(const_val);
            if (VALID_PTR(real_argc)) *real_argc = 2;
        }
        return is_ram + (1 << 1) + 1;
    }

    argc = parse_len = 0;
    argc = sscanf(arg, "%[a-z]%n", name, &parse_len);
    LOG(printf( "[a-z]\n"
                "sscanf res : %d\n"
                "name       : \"%s\"\n"
                "const_value: \"%s\"\n"
                "parse len  : %d\n"
                "arg len    : %d\n\n",
                argc, name, const_val, parse_len, arg_len);
    );
    if (argc == 1 && get_reg_by_name(&reg_tmp, name) != -1 && (strlen(name) == arg_len)) {
        if (VALID_PTR(argv)) {
            argv[0] = get_reg_by_name(&reg_tmp, name);
            if (VALID_PTR(real_argc)) *real_argc = 1;
        }
        return is_ram + (1 << 1) + 0;
    }

    argc = parse_len = 0;
    argc = sscanf(arg, "%[0-9]%n", const_val, &parse_len);
    LOG(printf( "[0-9]\n"
                "sscanf res : %d\n"
                "name       : \"%s\"\n"
                "const_value: \"%s\"\n"
                "parse len  : %d\n"
                "arg len    : %d\n",
                argc, name, const_val, parse_len, arg_len);
    );
    if (argc == 1 && (strlen(const_val) == arg_len)) {
        if (VALID_PTR(argv)) {
            argv[1] = atoi(const_val);
            if (VALID_PTR(real_argc)) *real_argc = 1;
        }
        return is_ram + (0 << 1) + 1;
    }

    return -1;
}

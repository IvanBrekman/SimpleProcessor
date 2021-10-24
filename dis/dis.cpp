//
// Created by ivanbrekman on 15.10.2021.
//

#include <cstdlib>
#include <cstring>
#include <cerrno>

#include "../libs/baselib.h"
#include "../libs/file_funcs.h"

#include "../arch/helper.h"
#include "../arch/commands.h"
#include "../arch/labels.h"

#include "dis.h"

Labels labels = { };

int main(int argc, char** argv) {
    if (argc < 3) {
        printf(RED "Cant parse executable file path or source file path" NATURAL "\n");
        return exit_codes::INVALID_SYNTAX;
    }

    LOG1(printf("------start disassembly------\n"););
    int exit_code = disassembly(argv[1], argv[2]);
    LOG1(printf("------end   disassembly------\n\n"););

    return exit_code;
}

int disassembly(const char* executable_file, const char* source_file) {
    assert(VALID_PTR(source_file)     && "Incorrect source_file ptr");
    assert(VALID_PTR(executable_file) && "Incorrect executable_file ptr");

    int n_commands = -1;
    errno = 0;
    BinCommand* mcodes = read_mcodes(executable_file, &n_commands);
    if (errno != 0) {
        printf(RED  "Error while reading mashine codes from executable file\n%s\n" NATURAL, error_desc(errno));
        return exit_codes::INVALID_SYNTAX;
    }

    Text* tcom = get_tcom_from_mcodes(mcodes, n_commands);
    LOG1(printf("All commands (dis)\n");
        for (int i = 0; i < n_commands; i++) {
            print_text((const Text*)&tcom[i]);
        }
    );
    for (int i = 0; i < n_commands; i++) {
        write_buffer_to_file(source_file, i == 0 ? "w" : "a", (const Text*)&tcom[i], " ");
    }

    return exit_codes::OK;
}

Text* get_tcom_from_mcodes(BinCommand* mcodes, int n_commands) {
    Text* tcom = (Text*) calloc(n_commands, sizeof(Text));

    labels_ctor(&labels);
    for (int i = 0; i < n_commands; i++) {
        BinCommand mcode = mcodes[i];
        int n_args = 1 + 1;

        char** array = (char**) calloc(n_args, sizeof(char*));
        array[0] = (char*)command_desc((int)mcode.sgn.cmd);
        array[1] = arg_desc(&mcode);

        Text cmd = convert_to_text((const char**)array, n_args);
        tcom[i] = cmd;

        if (ALL_COMMANDS[mcode.sgn.cmd].args_type == 0b0000000000000010) {
            write_label(&labels, "label_", mcode.argv[2]);
        }
    }

    labels_dtor(&labels);
    return tcom;
}

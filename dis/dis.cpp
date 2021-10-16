//
// Created by ivanbrekman on 15.10.2021.
//

#include <cstdlib>

#include "../libs/baselib.h"
#include "../libs/file_funcs.h"
#include "../arch/helper.h"

#include "dis.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        printf(RED "Cant parse executable file path or source file path\n" NATURAL);
        return INVALID_SYNTAX;
    }

    disassembly(argv[1], argv[2]);
}

int disassembly(const char* executable_file, const char* source_file) {
    assert(VALID_PTR(source_file,     char) && "Incorrect source_file ptr");
    assert(VALID_PTR(executable_file, char) && "Incorrect executable_file ptr");

    int n_commands;
    BinCommand* mcodes = read_mcodes(executable_file, &n_commands);

    Text* tcom = get_tcom_from_mcodes(mcodes, n_commands);
    for (int i = 0; i < n_commands; i++) {
        print_text(&tcom[i]);
    }
    for (int i = 0; i < n_commands; i++) {
        print_text((const Text*)&tcom[i]);
        write_buffer_to_file(source_file, i == 0 ? "w" : "a", (const Text*)&tcom[i], " ");
    }

    return 1;
}

Text* get_tcom_from_mcodes(BinCommand* mcodes, int n_commands) {
    Text* tcom = (Text*) calloc(n_commands, sizeof(Text));

    for (int i = 0; i < n_commands; i++) {
        BinCommand mcode = mcodes[i];
        int n_args = 1 + (int)mcode.sgn.argc;

        char** array = (char**) calloc(n_args, sizeof(char*));
        array[0] = (char*)command_desc((int)mcode.sgn.cmd);
        for (int arg = 0; arg < n_args - 1; arg++) {
            array[arg + 1] = to_string(mcode.argv[arg]);
        }

        Text cmd = convert_to_text((const char**)array, n_args);
        tcom[i] = cmd;
    }

    return tcom;
}

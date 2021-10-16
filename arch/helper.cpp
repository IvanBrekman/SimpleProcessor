//
// Created by ivanbrekman on 15.10.2021.
//

#include <cstdio>
#include <cstring>

#include "../libs/baselib.h"
#include "../libs/file_funcs.h"
#include "helper.h"

void print_command (BinCommand* cmd) {
    printf("   argc  cmd      argv\n");

    printf("| { %02d | %03d } , ", cmd->sgn.argc, cmd->sgn.cmd);
    printf("{ ");
    for (int i = 0; i < cmd->sgn.argc; i++) {
        printf("%d", cmd->argv[i]);
        if (i + 1 < cmd->sgn.argc) printf(", ");
    }
    printf(" } |  %s\n", command_desc(cmd->sgn.cmd));
}
void print_commands(BinCommand* cmds, int n_commands) {
    printf("Commands:\n");
    for (int i = 0; i < n_commands; i++) {
        print_command(&cmds[i]);
    }
}

int         command_type(const char* command) {
    assert(VALID_PTR(command, char) && "Invalid BinCommand ptr");

    if (strcmp(command, "push")   == 0) return PUSH;
    if (strcmp(command, "pop")    == 0) return POP;
    if (strcmp(command, "add")    == 0) return ADD;
    if (strcmp(command, "sub")    == 0) return SUB;
    if (strcmp(command, "mul")    == 0) return MUL;
    if (strcmp(command, "verify") == 0) return VERIFY;
    if (strcmp(command, "dump")   == 0) return DUMP;
    if (strcmp(command, "print")  == 0) return PRINT;
    if (strcmp(command, "hlt")    == 0) return HLT;

    return UNKNOWN;
}
const char* command_desc(int command) {
    return COMMANDS[command];
}

BinCommand* read_mcodes(const char* executable_file, int* n_commands) {
    assert(VALID_PTR(executable_file, char) && "Incorrect executable_file ptr");

    FILE* exe_file = fopen(executable_file, "rb");
    assert(VALID_PTR(exe_file, FILE) && "Cant open file with mode wb");

    int fsize = file_size(executable_file);
    assert(fsize % sizeof(BinCommand) == 0 && "Executable file is damaged");

    *n_commands = fsize / (int)sizeof(BinCommand);
    BinCommand* commands = (BinCommand*) calloc(*n_commands, sizeof(BinCommand));

    int wr_com = (int)fread(commands, sizeof(BinCommand), *n_commands, exe_file);

    printf("Read elems: %d\n", wr_com);
    assert(wr_com * sizeof(BinCommand) == fsize && "File size and number of read bytes arent equal");

    fclose(exe_file);
    return commands;
}
int         write_mcodes(const BinCommand* mcodes, int n_commands, const char* executable_file) {
    assert(VALID_PTR(mcodes, BinCommand) && "Incorrect mcodes ptr");
    assert(VALID_PTR(executable_file, char) && "Incorrect executable_file ptr");

    FILE* exe_file = fopen(executable_file, "wb");
    assert(VALID_PTR(exe_file, FILE) && "Cant open file with mode wb");

    int wr_com = (int)fwrite(mcodes, sizeof(BinCommand), n_commands, exe_file);
    printf("Written elems: %d\n"
           "n_commands:    %d\n"
           "size BinCommand:  %zd\n", wr_com, n_commands, sizeof(BinCommand));

    fclose(exe_file);
    return wr_com;
}

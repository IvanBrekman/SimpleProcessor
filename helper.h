//
// Created by ivanbrekman on 15.10.2021.
//

#ifndef SIMPLEPROCESSOR_HELPER_H
#define SIMPLEPROCESSOR_HELPER_H

#include <cmath>
#include <cstdio>
#include <cassert>

enum commands {
    HLT     =  0,
    PUSH    =  1,
    POP     =  2,

    ADD     =  3,
    SUB     =  4,
    MUL     =  5,

    VERIFY  =  6,
    DUMP    =  7,
    PRINT   =  8,

    UNKNOWN = 9,
};
static const char* COMMANDS[] = {
        "hlt", "push", "pop", "add", "sub", "mul", "verify", "dump", "print", "unknown"
};

const int BITS_TO_ARGV = 2;
const int MAX_ARGV     = (int)pow(2, BITS_TO_ARGV);

struct signature_ {
    unsigned argc : BITS_TO_ARGV;
    unsigned cmd  : 8 - BITS_TO_ARGV;
};

struct Command {
    signature_ sgn = {};
    int argv[4] = {};
};

void print_command (Command* cmd);
void print_commands(Command* cmds, int n_commands);

int         command_type(const char* command);
const char* command_desc(int command);


Command* read_mcodes(const char* executable_file, int* n_commands);
int     write_mcodes(const Command* mcodes, int n_commands, const char* executable_file);

#endif //SIMPLEPROCESSOR_HELPER_H

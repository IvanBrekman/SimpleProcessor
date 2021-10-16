//
// Created by ivanbrekman on 15.10.2021.
//

#ifndef SIMPLEPROCESSOR_HELPER_H
#define SIMPLEPROCESSOR_HELPER_H

#include <cmath>
#include <cstdio>
#include <cassert>

const int BITS_TO_ARGV = 2;                             // Max argv amount dependent
const int MAX_ARGV     = 4;

enum exit_codes {
    OK             =  0,
    BREAK          = -1,
    INVALID_SYNTAX = -2
};
enum compile_errors {
    UNKNOWN_COMMAND      = -1,
    INCORRECT_ARG_AMOUNT = -2,
    INCORRECT_ARG_TYPE   = -3
};
enum commands {                                         // Commands depended
    HLT     =  0,
    PUSH    =  1,
    POP     =  2,

    ADD     =  3,
    SUB     =  4,
    MUL     =  5,

    VERIFY  =  6,
    DUMP    =  7,
    PRINT   =  8,

    UNKNOWN =  -1
};

struct signature_ {
    unsigned argc : BITS_TO_ARGV;
    unsigned cmd  : 8 - BITS_TO_ARGV;
};

struct BinCommand {
    signature_ sgn = {};
    int argv[MAX_ARGV] = {};
};

const char* compile_error_desc(int error_code);

void print_command (BinCommand* cmd);
void print_commands(BinCommand* cmds, int n_commands);

int         command_type(const char* command);
const char* command_desc(int command);


BinCommand* read_mcodes(const char* executable_file, int* n_commands);
int         write_mcodes(const BinCommand* mcodes, int n_commands, const char* executable_file);

#endif //SIMPLEPROCESSOR_HELPER_H

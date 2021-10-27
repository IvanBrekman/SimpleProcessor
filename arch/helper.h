//
// Created by ivanbrekman on 15.10.2021.
//

#ifndef SIMPLEPROCESSOR_HELPER_H
#define SIMPLEPROCESSOR_HELPER_H

#include <cmath>
#include <cstdio>
#include <cassert>

#include "../config.h"

const int MAX_LABELS    = 50;
const int MAX_REGISTERS = 4;
const int RAM_SIZE      = 4096;
const int VRAM_START    = 2048;

const int TYPES_AMOUNT = 4;
const int LABEL_BIT    = 0;
const int NUMBER_BIT   = 1;
const int REGISTER_BIT = 2;
const int RAM_BIT      = 3;

static const char* REG_NAMES[MAX_REGISTERS] = { "ax", "bx", "cx", "dx" };

const int BITS_TO_ARGV  = 3;                             // Max argv amount dependent
const int MAX_ARGV      = 8;

enum exit_codes {
    OK             =  0,
    EXIT           = -1,
    BREAK          = -2,
    INVALID_SYNTAX = -3,
    NO_OBVIOUS_END = -4
};
enum compile_errors {
    UNKNOWN_COMMAND         = -15,
    INCORRECT_ARG_AMOUNT    = -16,
    INCORRECT_ARG_TYPE      = -17,
    REPEAT_LABEL_DEFINITION = -18,
    UNKNOWN_LABEL           = -19
};
enum binary_errors {
    DAMAGED_BINARY          = -63,
    READ_PARTIAL_HEADER     = -64,
    INCORRECT_VERSION       = -65
};

struct signature_ {
    unsigned argc : BITS_TO_ARGV;
    unsigned cmd  : 8 - BITS_TO_ARGV;
};

struct BinCommand {
    signature_ sgn     = {};
    int args_type      =  0;
    int argv[MAX_ARGV] = {};
};

const char* error_desc(int error_code);

void print_command (BinCommand* cmd,  int cmd_num, FILE* log=stdout, void* lab=NULL);

int         command_type(const char* command);
const char* command_desc(int command);

char* arg_desc(const BinCommand* mcode, void* lab=NULL);

BinCommand* read_mcodes(const char* executable_file, int* n_commands);
int         write_mcodes(const BinCommand* mcodes, int n_commands, const char* executable_file);

#endif //SIMPLEPROCESSOR_HELPER_H

//
// Created by ivanbrekman on 16.10.2021.
//

#ifndef SIMPLEPROCESSOR_COMMANDS_H
#define SIMPLEPROCESSOR_COMMANDS_H

#include "helper.h"

const CommandParameters* ALL_COMMANDS {
    { "hlt",    0, 0, {   }, execute_hlt    },
    { "push",   1, 1, { 1 }, execute_push   },
    { "pop",    2, 0, {   }, execute_pop    },
    { "add",    3, 0, {   }, execute_add    },
    { "sub",    4, 0, {   }, execute_sub    },
    { "mul",    5, 0, {   }, execute_mul    },
    { "verify", 6, 0, {   }, execute_verify },
    { "dump",   7, 0, {   }, execute_dump   },
    { "print",  8, 0, {   }, execute_print  }
};

int init_stack();

int execute_hlt   (int argc, int* argv);

int execute_push  (int argc, int* argv);
int execute_pop   (int argc, int* argv);

int execute_add   (int argc, int* argv);
int execute_sub   (int argc, int* argv);
int execute_mul   (int argc, int* argv);

int execute_verify(int argc, int* argv);
int execute_dump  (int argc, int* argv);
int execute_print (int argc, int* argv);


#endif //SIMPLEPROCESSOR_COMMANDS_H

//
// Created by ivanbrekman on 15.10.2021.
//

#ifndef SIMPLEPROCESSOR_ASM_H
#define SIMPLEPROCESSOR_ASM_H

#include "../libs/file_funcs.h"

int assembly(const char* source_file, const char* executable_file);

Text*       get_tcom(const Text* data);
Text        check_tcom(const Text* tcom, int n_commands);
BinCommand* get_mcodes_from_tcom(const Text* commands, int n_commands);

#endif //SIMPLEPROCESSOR_ASM_H

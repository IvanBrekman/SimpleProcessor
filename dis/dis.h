//
// Created by ivanbrekman on 15.10.2021.
//

#ifndef SIMPLEPROCESSOR_DIS_H
#define SIMPLEPROCESSOR_DIS_H

#include "../libs/file_funcs.h"
#include "../arch/helper.h"

int disassembly(const char* executable_file, const char* source_file);

Text* get_tcom_from_mcodes(BinCommand* mcodes, int* n_commands);

#endif //SIMPLEPROCESSOR_DIS_H

//
// Created by ivanbrekman on 20.10.2021.
//

#ifndef SIMPLEPROCESSOR_REGISTERS_H
#define SIMPLEPROCESSOR_REGISTERS_H

#include "helper.h"

struct Registers {
    int regs[MAX_REGISTERS] = {
        poisons::UNINITIALIZED_INT,
        poisons::UNINITIALIZED_INT,
        poisons::UNINITIALIZED_INT,
        poisons::UNINITIALIZED_INT
    };
    const char* names[MAX_REGISTERS] = { "", "", "", "" };
};

int    registers_ctor(Registers* reg,  const char* names[MAX_REGISTERS]);
int    registers_dtor(Registers* reg);

int   get_reg_by_name(Registers* reg,  const char* name);
int         print_reg(Registers* reg);

int      write_to_reg(Registers* reg, int reg_index, int value);
int     read_from_reg(Registers* reg, int reg_index);
int can_read_from_reg(Registers* reg, int reg_index);

#endif //SIMPLEPROCESSOR_REGISTERS_H

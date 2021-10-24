//
// Created by ivanbrekman on 20.10.2021.
//

#include <cassert>
#include <cstring>

#include "../libs/baselib.h"
#include "registers.h"


int    init_registers(Registers* reg, const char* names[]) {
    assert(VALID_PTR(reg)   && "Invalid reg ptr");
    assert(VALID_PTR(names) && "Invalid names ptr");

    for (int i = 0; i < MAX_REGISTERS; i++) {
        reg->regs[i]  = poisons::UNINITIALIZED_INT;
        reg->names[i] = names[i];
    }

    return MAX_REGISTERS;
}
int   get_reg_by_name(Registers* reg, const char* name) {
    for (int i = 0; i < MAX_REGISTERS; i++) {
        if (strcmp(name, reg->names[i]) == 0) {
            return i;
        }
    }

    return -1;
}
int         print_reg(Registers* reg) {
    for (int i = 0; i < MAX_REGISTERS; i++) {
        printf("%s - % 2d\n", reg->names[i], reg->regs[i]);
    }

    return MAX_REGISTERS;
}


int      write_to_reg(Registers* reg, int reg_index, int value) {
    assert(VALID_PTR(reg) && "Invalid reg ptr");
    
    reg->regs[reg_index] = value;
    return value;
}
int     read_from_reg(Registers* reg, int reg_index) {
    assert(VALID_PTR(reg) && "Invalid reg ptr");

    if (!can_read_from_reg(reg, reg_index)) {
        return poisons::UNINITIALIZED_INT;
    }

    return reg->regs[reg_index];

}
int can_read_from_reg(Registers* reg, int reg_index) {
    assert(VALID_PTR(reg) && "Invalid reg ptr");

    return reg_index >= 0 && reg_index < MAX_REGISTERS && reg->regs[reg_index] != poisons::UNINITIALIZED_INT;
}

//
// Created by ivanbrekman on 17.10.2021.
//

#include "DSL/commands_syntax.h"

COMMAND_DEFINITION( hlt,   0, 0, 0, 0b0000000000000000,  {
    return EXIT_;
})

COMMAND_DEFINITION( push,  1, 1, 1, 0b1111110011111100,  {
    int arg = 0;
    if (HAS_REGISTER) arg += read_from_reg(REG, ARG(0, REGISTER_BIT));
    if (HAS_NUMBER)   arg += ARG(0, NUMBER_BIT);
    if (HAS_RAM)      arg  = RAM(arg);
    
    PUSH(arg);

    return OK_;
})

COMMAND_DEFINITION( pop,   2, 0, 1, 0b1111110000110000,  {
    int pop_value = POP;

    if (args_type > 0) {
        if (HAS_RAM) {
            int arg = 0;
            if (HAS_REGISTER) arg += read_from_reg(REG, ARG(0, REGISTER_BIT));
            if (HAS_NUMBER)   arg += ARG(0, NUMBER_BIT);
            RAM(arg) = pop_value;
        } else {
            write_to_reg(REG, ARG(0, REGISTER_BIT), pop_value);
        }
    }

    return OK_;
})

COMMAND_DEFINITION( add,   3, 0, 0, 0b0000000000000000,  {
    PUSH(POP + POP);
    return OK_;
})

COMMAND_DEFINITION( sub,   4, 0, 0, 0b0000000000000000,  {
    int arg1 = POP;
    int arg2 = POP;

    PUSH(arg2 - arg1);
    return OK_;
})

COMMAND_DEFINITION( mul,   5, 0, 0, 0b0000000000000000,  {
    PUSH(POP * POP);
    return OK_;
})

COMMAND_DEFINITION( vrf,   6, 0, 0, 0b0000000000000000,  {
    int err = Stack_error(STACK);
    printf("Stack Verify: %s (%d)\n", Stack_error_desc(err), err);

    return OK_;
})

COMMAND_DEFINITION( dump,  7, 0, 0, 0b0000000000000000,  {
    DUMP;
    return OK_;
})

COMMAND_DEFINITION( out,   8, 0, 0, 0b0000000000000000,  {
    OUT;
    return OK_;
})

COMMAND_DEFINITION( prt,   9, 0, 0, 0b0000000000000000,  {
    PRINT;
    return OK_;
})

COMMAND_DEFINITION( abrt, 10, 0, 0, 0b0000000000000000,  {
    return BREAK_;
})

COMMAND_DEFINITION( cat,  11, 0, 0, 0b0000000000000000,  {
   printf("____________________$$____________$$_____\n"
          "_____________ _____$___$________$___$____\n"
          "__________________$_____$$$$$$_____ $____\n"
          "__________________$____sss___sss____$____\n"
          "________________ _$____@_____@_____$_____\n"
          "_________________$ _______$$$_______$____\n"
          "_____$$$$$$$$_____$_______^_______$______\n"
          "_ __$$________$______$$_________$$_______\n"
          "____$_________$_____$___$ $$$$$___$______\n"
          "_______$______$____$__$________$__$______\n"
          "_______$____ _$____$__$__________$__$____\n"
          "______$____$___$$$$__$__________$_ _$$$$_\n"
          "_____$___$____$____$__$________$___$___$_\n"
          "_____$__$__ ___$____$__$________$__$____$\n"
          "____$___$______$____$__$____$ _$__$____$_\n"
          "______$__$______$____$___$_$_____$___$___\n"
          "_______$ ___$$$$$_$___$___$_$____$___$___\n"
          "__________$$$$$_$____$____$__ ___$____$__\n"
          "________________$$$_$_____$______$_$$$___\n"
          "_________ ____________$$$$___$$$$$ ______\n");

   return OK_;
})

COMMAND_DEFINITION( jmp,  12, 1, 1, 0b0000000000000010,  {
    IP = ARG(0, LABEL_BIT) - 1;
    return IP;
})

#define COND_JUMP_DEFINITION(name, code, sign)                                  \
COMMAND_DEFINITION( name, code, 1, 1, 0b0000000000000010, {                     \
    int first  = POP;                                                           \
    int second = POP;                                                           \
                                                                                \
    if (second sign first) {                                                    \
        IP = ARG(0, LABEL_BIT) - 1;                                             \
    }                                                                           \
                                                                                \
    return IP;                                                                  \
})

#include "cond_jumps_definition.h"
#undef COND_JUMP_DEFINITION
// 18

COMMAND_DEFINITION( call, 19, 1, 1, 0b0000000000000010, {
    PUSH_C(IP + 1);

    IP = ARG(0, LABEL_BIT) - 1;
    return IP;
})

COMMAND_DEFINITION( ret,  20, 0, 0, 0b0000000000000000,  {
    IP = POP_C - 1;
    return IP;
})

COMMAND_DEFINITION( draw, 21, 2, 2, 0b1111110011111100, {
    int arg1 = 0;
    int arg2 = 0;

    if (HAS_REGISTER) arg1 += read_from_reg(REG, ARG(0, REGISTER_BIT));
    if (HAS_NUMBER)   arg1 += ARG(0, NUMBER_BIT);
    if (HAS_RAM)      arg1  = RAM(arg1);

    if (HAS_REGISTER) arg2 += read_from_reg(REG, ARG(1, REGISTER_BIT));
    if (HAS_NUMBER)   arg2 += ARG(1, NUMBER_BIT);
    if (HAS_RAM)      arg2  = RAM(arg2);

    printf("arg1 - arg2: %d - %d\n", arg1, arg2);
    for (int y = 0; y < arg1; y++) {
        for (int x = 0; x < arg2; x++) {
            printf("%c", RAM(VRAM_START + y * arg2 + x) == 0 ? '-' : '*');
        }
        printf("\n");
    }

    return OK_;
})

COMMAND_DEFINITION( mod, 22, 1, 1, 0b0000000000000100, {
    PUSH(POP % ARG(0, NUMBER_BIT));
    return OK_;
})

COMMAND_DEFINITION( in,  23, 0, 0, 0b0000000000000000, {
    printf("Input number..\n");
    
    int num = poisons::UNINITIALIZED_INT;
    while (scanf("%d", &num) != 1) {
        printf("NaN\n");
        while (getchar() != '\n') continue;
    }

    PUSH(num);
    return OK_;
})

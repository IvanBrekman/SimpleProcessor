//
// Created by ivanbrekman on 17.10.2021.
//

COMMAND_DEFINITION( "hlt",   0, 0, 0, 0b0000000000000000, execute_hlt,  {
    return exit_codes::EXIT;
})

COMMAND_DEFINITION( "push",  1, 1, 1, 0b1111110011111100, execute_push, {
    int arg = 0;
    if (extract_bit(args_type, REGISTER_BIT)) {
        arg += read_from_reg(&processor.regs, argv[0]);
    }
    if (extract_bit(args_type, NUMBER_BIT)) {
        arg += argv[1];
    }
    if (extract_bit(args_type, RAM_BIT)) {
        arg  = processor.RAM[arg];
    }
    
    push(&processor.stack, arg);

    return exit_codes::OK;
})

COMMAND_DEFINITION( "pop",   2, 0, 1, 0b1111110000110000, execute_pop,  {
    int pop_value = pop(&processor.stack);

    if (args_type > 0) {
        if (extract_bit(args_type, RAM_BIT)) {
            int arg = 0;
            if (extract_bit(args_type, REGISTER_BIT)) {
                arg += read_from_reg(&processor.regs, argv[0]);
            }
            if (extract_bit(args_type, NUMBER_BIT)) {
                arg += argv[1];
            }
            processor.RAM[arg] = pop_value;
        } else {
            write_to_reg(&processor.regs, argv[0], pop_value);
        }
    }

    return exit_codes::OK;
})

COMMAND_DEFINITION( "add",   3, 0, 0, 0b0000000000000000, execute_add,  {
    push(&processor.stack, pop(&processor.stack) + pop(&processor.stack));

    return exit_codes::OK;
})

COMMAND_DEFINITION( "sub",   4, 0, 0, 0b0000000000000000, execute_sub,  {
    push(&processor.stack, -pop(&processor.stack) + pop(&processor.stack));

    return exit_codes::OK;
})

COMMAND_DEFINITION( "mul",   5, 0, 0, 0b0000000000000000, execute_mul,  {
    push(&processor.stack, pop(&processor.stack) * pop(&processor.stack));

    return exit_codes::OK;
})

COMMAND_DEFINITION( "vrf",   6, 0, 0, 0b0000000000000000, execute_vrf,  {
    int err = Stack_error(&processor.stack);
    printf("Stack Verify: %s (%d)\n", Stack_error_desc(err), err);

    return exit_codes::OK;
})

COMMAND_DEFINITION( "dump",  7, 0, 0, 0b0000000000000000, execute_dump, {
    stack_dump(processor.stack, "System dump call");

    return exit_codes::OK;
})

COMMAND_DEFINITION( "out",   8, 0, 0, 0b0000000000000000, execute_out,  {
    printf("%d\n", pop(&processor.stack));

    return exit_codes::OK;
})

COMMAND_DEFINITION( "prt",   9, 0, 0, 0b0000000000000000, execute_prt,  {
    print_stack(&processor.stack);

    return exit_codes::OK;
})

COMMAND_DEFINITION( "abrt", 10, 0, 0, 0b0000000000000000, execute_abr,  {
    return exit_codes::BREAK;
})

COMMAND_DEFINITION( "cat",  11, 0, 0, 0b0000000000000000, execute_cat,  {
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

   return exit_codes::OK;
})

COMMAND_DEFINITION( "jmp",  12, 1, 1, 0b0000000000000010, execute_jmp,  {
    processor.ip = argv[2] - 1;
    return processor.ip;
})

#define COND_JUMP_DEFINITION(name, code, sign)                                  \
COMMAND_DEFINITION( #name, code, 1, 1, 0b0000000000000010, execute_ ## name, {  \
    int first  = pop(&processor.stack);                                         \
    int second = pop(&processor.stack);                                         \
                                                                                \
    if (second sign first) {                                                    \
        processor.ip = argv[2] - 1;                                             \
    }                                                                           \
                                                                                \
    return processor.ip;                                                        \
})

#include "cond_jumps_definition.h"
#undef COND_JUMP_DEFINITION
// 18

COMMAND_DEFINITION( "call", 19, 1, 1, 0b0000000000000010, execute_call, {
    push(&processor.call_stack, processor.ip + 1);

    processor.ip = argv[2] - 1;
    return processor.ip;
})

COMMAND_DEFINITION( "ret",  20, 0, 0, 0b0000000000000000, execute_ret,  {
    processor.ip = pop(&processor.call_stack) - 1;
    return processor.ip;
})

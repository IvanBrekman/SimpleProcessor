//
// Created by ivanbrekman on 06.10.2021.
//

#include <cstdlib>
#include <cstring>
#include <cassert>

#include "libs/baselib.h"
#include "libs/file_funcs.h"

#include "processor.h"
#include "libs/stack.h"

//int execute_commands(const Text* commands, size_t size, Stack* stack) {
//    assert(VALID_PTR(stack, Stack)   && "Invalid stack ptr");
//    assert(VALID_PTR(commands, Text) && "Invalid commands ptr");
//
//    for (int i = 0; i < size; i++) {
//        String* cmd = commands[i].text;
//        switch (command_type(cmd[0].ptr)) {
//            case PUSH:
//                push(stack, atoi(cmd[1].ptr));
//                break;
//            case POP:
//                pop(stack);
//                break;
//            case ADD:
//                push(stack, pop(stack) + pop(stack));
//                break;
//            case SUB:
//                push(stack, -pop(stack) + pop(stack));
//                break;
//            case MUL:
//                push(stack, pop(stack) * pop(stack));
//                break;
//            case VERIFY: {
//                int err = Stack_error(stack);
//                printf("Stack Verify: %s (%d)\n", Stack_error_desc(err), err);
//                break;
//            }
//            case DUMP:
//                stack_dump(*stack, "System dump call");
//                break;
//            case PRINT:
//                print_stack(stack);
//                break;
//            case HLT:
//                return BREAK;
//            default:
//                assert(0 && "Fatal error. Unknown Command");
//        }
//    }
//
//    return 0;
//}

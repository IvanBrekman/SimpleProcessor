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

char* exit_code_desc(int exit_code) {
    switch (exit_code) {
        case BREAK:
            return "Program was aborted by system hlt signal";
        default:
            return "Unknown exit code";
    }
}

Text* get_commands(Text* data) {
    Text* commands = (Text*)calloc(data->lines, sizeof(Text));

    for (int i = 0; i < data->lines; i++) {
        char* str_command = data->text[i].ptr;

        int args = replace(str_command, data->text[i].len, ' ', '\0') + 1;
        Text command = {
                str_command,
                data->text[i].len + 1,
                (String*)calloc(args, sizeof(String)),
                (size_t)args
        };
        load_string_pointers(&command);

        commands[i] = command;
    }

    return commands;
}

int   command_type(const char* command) {
    if (strcmp(command, "push")   == 0) return PUSH;
    if (strcmp(command, "pop")    == 0) return POP;
    if (strcmp(command, "add")    == 0) return ADD;
    if (strcmp(command, "sub")    == 0) return SUB;
    if (strcmp(command, "mul")    == 0) return MUL;
    if (strcmp(command, "verify") == 0) return VERIFY;
    if (strcmp(command, "dump")   == 0) return DUMP;
    if (strcmp(command, "print")  == 0) return PRINT;
    if (strcmp(command, "hlt")    == 0) return HLT;
    return -666;
}
int analyze_commands(const Text* commands, size_t size) {
    for (int i = 0; i < size; i++) {
        String* cmd = commands[i].text;
        switch (command_type(cmd[0].ptr)) {
            case PUSH:
            case POP:
                if (commands[i].lines != 2) {
                    return 0;
                }
                if (!is_number(cmd[1].ptr)) {
                    return 0;
                }
                break;
            case ADD:
            case SUB:
            case MUL:
            case VERIFY:
            case DUMP:
            case PRINT:
            case HLT:
                if (commands[i].lines != 1) {
                    return 0;
                }
                break;
            default:
                return 0;
        }
    }
}
int execute_commands(const Text* commands, size_t size, Stack* stack) {
    for (int i = 0; i < size; i++) {
        String* cmd = commands[i].text;
        printf("command: %s\n", cmd->ptr);
        switch (command_type(cmd[0].ptr)) {
            case PUSH:
                push(stack, atoi(cmd[1].ptr));
                break;
            case POP:
                pop(stack);
                break;
            case ADD:
                push(stack, pop(stack) + pop(stack));
                break;
            case SUB:
                push(stack, -pop(stack) + pop(stack));
                break;
            case MUL:
                push(stack, pop(stack) * pop(stack));
                break;
            case VERIFY: {
                int err = Stack_error(stack);
                printf("Stack Verify: %s (%d)\n", Stack_error_desc(err), err);
                break;
            }
            case DUMP:
                stack_dump(*stack, "System dump call");
                break;
            case PRINT:
                print_stack(stack);
                break;
            case HLT:
                return BREAK;
            default:
                assert(0 && "Fatal error. Unknown command");
        }
    }

    return 0;
}

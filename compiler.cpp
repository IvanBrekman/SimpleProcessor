//
// Created by ivanbrekman on 09.10.2021.
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
//int analyze_commands(const Text* commands, size_t size) {
//    assert(VALID_PTR(commands, Text) && "Invalid commands ptr");
//
//    for (int i = 0; i < size; i++) {
//        String* cmd = commands[i].text;
//        switch (command_type(cmd[0].ptr)) {
//            case PUSH:
//            case POP:
//                if (commands[i].lines != 2) {
//                    return 0;
//                }
//                if (!is_number(cmd[1].ptr)) {
//                    return 0;
//                }
//                break;
//            case ADD:
//            case SUB:
//            case MUL:
//            case VERIFY:
//            case DUMP:
//            case PRINT:
//            case HLT:
//                if (commands[i].lines != 1) {
//                    return 0;
//                }
//                break;
//            default:
//                return 0;
//        }
//    }
//    return 1;
//}

int prepare_binary(const Text* commands, size_t size) {
    
}

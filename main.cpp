//
// Created by ivanbrekman on 04.10.2021.
//

#include "config.h"

#include <cstdio>

#include "libs/stack.h"
#include "libs/file_funcs.h"

#include "processor.h"
#include "helper.h"
#include "asm/asm.h"
#include "dis/dis.h"

int main(int argc, char** argv) {
    printf("%zd", sizeof(char*));
    Command cmd = {};
    cmd.sgn = { 3, 4 };
    cmd.argv[0] = 1;
    cmd.argv[1] = 3;
    cmd.argv[2] = 4;

    print_command(&cmd);

    printf("\n----------------\n\n");
    //assembly("../commands.txt", "a.cat");
    disassembly("a.cat", "a.txt");

    return 0;
}

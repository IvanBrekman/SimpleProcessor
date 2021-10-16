//
// Created by ivanbrekman on 04.10.2021.
//

#include "config.h"

#include <cstdio>

#include "arch/helper.h"
#include "asm/asm.h"
#include "dis/dis.h"
#include "CPU/cpu.h"

int main(int argc, char** argv) {

    assembly("../commands.txt", "a.cat");
    disassembly("a.cat", "a.txt");
    execute("a.cat");

    return 0;
}

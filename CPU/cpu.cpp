//
// Created by ivanbrekman on 15.10.2021.
//

#include "../arch/helper.h"

int execute(const char* execute_file) {
    int n_commands = -1;
    BinCommand* mcodes = read_mcodes(execute_file, &n_commands);

    return 1;
}

int execute_commands(BinCommand* mcodes) {

}

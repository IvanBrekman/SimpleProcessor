//
// Created by ivanbrekman on 15.10.2021.
//

#include <cstdio>
#include <cstring>
#include <cerrno>

#include "../config.h"
#include "../libs/baselib.h"
#include "../libs/file_funcs.h"

#include "helper.h"
#include "commands.h"

const char* error_desc(int error_code) {
    switch (error_code) {
        case compile_errors::UNKNOWN_COMMAND:
            return "Unknown command";
        case compile_errors::INCORRECT_ARG_AMOUNT:
            return "Invalid arguments amount for this command";
        case compile_errors::INCORRECT_ARG_TYPE:
            return "Incorrect argument type for this command";
        
        case binary_errors::DAMAGED_BINARY:
            return "Data in executable file are damaged";
        case binary_errors::READ_PARTIAL_HEADER:
            return "Cant read full header in executable file";
        case binary_errors::INCORRECT_VERSION:
            return "Version in executable file doesnt match with processor version";
        default:
            return "Unknown error";
    }
}

void print_command (BinCommand* cmd) {
    printf("   argc  cmd      argv\n");

    printf("| { %02d | %03d } , ", cmd->sgn.argc, cmd->sgn.cmd);
    printf("{ ");
    for (int i = 0; i < cmd->sgn.argc; i++) {
        printf("%d", cmd->argv[i]);
        if (i + 1 < cmd->sgn.argc) printf(", ");
    }
    printf(" } |  %s\n", command_desc(cmd->sgn.cmd));
}
void print_commands(BinCommand* cmds, int n_commands) {
    printf("Commands:\n");
    for (int i = 0; i < n_commands; i++) {
        print_command(&cmds[i]);
    }
}

int         command_type(const char* command) {
    assert(VALID_PTR(command) && "Invalid BinCommand ptr");

    for (CommandParameters cmd_par : ALL_COMMANDS) {
        if (strcmp(command, cmd_par.name) == 0) {
            return cmd_par.code;
        }
    }

    return UNKNOWN;
}
const char* command_desc(int command) {
    return ALL_COMMANDS[command].name;
}

BinCommand* read_mcodes(const char* executable_file, int* n_commands) {
    assert(VALID_PTR(executable_file) && "Incorrect executable_file ptr");
    assert(VALID_PTR(n_commands) && "Incorrect n_commands ptr");

    FILE* exe_file = fopen(executable_file, "rb");
    assert(VALID_PTR(exe_file) && "Cant open file with mode wb");

    header received_header = { "", "" };
    int hdr_data = (int)fread(&received_header, sizeof(header), 1, exe_file);

    LOG(printf( "real signature: %s\n"
                "real version:   %s\n\n"
                "rec signature:  %s\n"
                "rec version:    %s\n\n",
                HEADER.signature, HEADER.version, received_header.signature, received_header.version);
    );
    if (hdr_data != 1) {
        errno = binary_errors::READ_PARTIAL_HEADER;
        return {};
    } else if (strcmp(received_header.signature, HEADER.signature) != 0) {
        errno = binary_errors::DAMAGED_BINARY;
        return {};
    } else if (strcmp(received_header.version, HEADER.version) != 0) {
        errno = binary_errors::INCORRECT_VERSION;
        return {};
    }

    int fsize = file_size(executable_file) - hdr_data * sizeof(header);
    assert(fsize % sizeof(BinCommand) == 0 && "Executable file is damaged");

    *n_commands = fsize / (int)sizeof(BinCommand);
    BinCommand* commands = (BinCommand*) calloc(*n_commands, sizeof(BinCommand));

    int wr_com = (int)fread(commands, sizeof(BinCommand), *n_commands, exe_file);

    LOG(printf("Read elems: %d\n", wr_com););
    assert(wr_com * sizeof(BinCommand) == fsize && "File size and number of read bytes arent equal");

    fclose(exe_file);
    return commands;
}
int         write_mcodes(const BinCommand* mcodes, int n_commands, const char* executable_file) {
    assert(VALID_PTR(mcodes) && "Incorrect mcodes ptr");
    assert(VALID_PTR(executable_file) && "Incorrect executable_file ptr");

    FILE* exe_file = fopen(executable_file, "wb");
    assert(VALID_PTR(exe_file) && "Cant open file with mode wb");

    LOG(printf( "signature: %s\n"
                "version:   %s\n\n", HEADER.signature, HEADER.version);
    );
    
    int hd_bts = (int)fwrite(&HEADER, sizeof(HEADER), 1, exe_file);
    fclose(exe_file);

    exe_file = fopen(executable_file, "ab");
    int wr_com = (int)fwrite(mcodes, sizeof(BinCommand), n_commands, exe_file);
    LOG(printf( "Written elems:    %d\n"
                "n_commands:       %d\n"
                "size BinCommand:  %zd\n\n", wr_com, n_commands, sizeof(BinCommand));
    );

    fclose(exe_file);
    return wr_com;
}

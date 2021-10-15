//
// Created by ivanbrekman on 15.10.2021.
//

#ifndef SIMPLEPROCESSOR_ASM_H
#define SIMPLEPROCESSOR_ASM_H

int assembly(const char* source_file, const char* executable_file);
Text* get_tcom(const Text* data);
Command* get_mcodes_from_tcom(const Text* commands, int n_commands);
int    write_mcodes(const Command* mcodes, int n_commands, const char* executable_file);

#endif //SIMPLEPROCESSOR_ASM_H

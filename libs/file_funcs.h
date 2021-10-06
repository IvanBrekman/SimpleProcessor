//
// Created by ivanbrekman on 26.08.2021.
//

#ifndef SIMPLEPROCESSOR_FILE_FUNCS_H
#define SIMPLEPROCESSOR_FILE_FUNCS_H

#include <cstdio>

struct String {
    char* ptr;
    size_t   len;
};

struct Text {
    char* data;
    size_t data_size;

    String* text;
    size_t lines;
};

int replace(char* string, size_t size, char old_symbol, char new_symbol, int n_replace=-1);

void free_text(Text* data);
void free_string(String* string);

int load_string_pointers(Text* text);
void print_text(const Text* data, char* sep=" ", char* end="\n");
void print_strings(const char** array, size_t size, char* sep=" ", char* end="\n");

FILE* open_file(const char* filename, const char mode[]);
int file_size(const char* filename);
Text get_text_from_file(const char* filename);

int write_text_to_file(const char* filename, const char mode[], const Text* data);
int write_buffer_to_file(const char* filename, const char mode[], const Text* data);
int write_strings_to_file(const char* filename, const char mode[], const char** data, int n_strings);

#endif //SIMPLEPROCESSOR_FILE_FUNCS_H

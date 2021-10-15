//
// Created by ivanbrekman on 26.08.2021.
//

#include <cstdio>
#include <cstdlib>
#include <cassert>

#include <cwchar>
#include <sys/stat.h>
#include <cstring>

#include "baselib.h"
#include "file_funcs.h"

//! Function replaces old_symbol to new_symbol in string n_replace times
//! \param string     pointer to string
//! \param size       size of string
//! \param old_symbol old symbol
//! \param new_symbol new symbol
//! \param n_replace  number or replacements (-1 if you want to replace all old symbols)
//! \return           number of replacements
//! \note function need string size, because if you want to
//!       replace '\0' symbol strlen function wont work correctly
int replace(char* string, size_t size, char old_symbol, char new_symbol, int n_replace) {
    assert(VALID_PTR(string, char));

    int n_rep = 0;

    for (int i = 0; i < size; i++) {
        if (n_rep >= n_replace && n_replace >= 0) {
            break;
        }
        if (string[i] == old_symbol) {
            string[i] = new_symbol;
            n_rep++;
        }
    }

    return n_rep;
}

void free_text(struct Text* data) {
    data->data = NULL;
    data->data_size = -1;

    for (int i = 0; i < data->lines; i++) {
        free_string(&(data->text[i]));
    }
    data->text = NULL;
    data->lines = -1;

    data = NULL;
}
void free_string(struct String* string) {
    string->ptr = NULL;
    string->len = -1;

    string = NULL;
}

//! Function prints text from struct
//! \param data pointer to struct
void print_text(const Text* data, char* sep, char* end) {
    assert(data != NULL);

    printf("[ ");
    for (int i = 0; i < data->lines; i++) {
        printf("%s%s", data->text[i].ptr, sep);
    }
    printf("]%s", end);
}
//! Function prints array of strings
//! \param array pointer to array of strings
//! \param size  size of array
void print_strings(const char** array, size_t size, char* sep, char* end) {
    assert(array != 0);

    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%s%s", array[i], sep);
    }
    printf("]%s", end);
}

//! Function load pointers of beginnings of strings to an array
//! \param dest_array pointer to array of String structures, where string will be written
//! \param data       analyzed data
//! \param data_size  data size
//! \return           1
int load_string_pointers(Text* text) {
    assert(text->text != NULL);
    assert(text->data != NULL);

    char* start_ptr = (char*)text->data;

    for (int i = 0, str_index = 0; i < text->data_size && str_index < text->lines; i++) {
        if (text->data[i] == '\0') {
            char* end_ptr = NULL;
            end_ptr = (char*)&(text->data[i]);

            struct String string = {
                    start_ptr,
                    (size_t)(end_ptr - start_ptr)
            };
            text->text[str_index++] = string;

            start_ptr = (char*)&(text->data[i + 1]);
        }
    }

    return 1;
}

//! Function opens file
//! \param filename path to file to open (absolute or relative)
//! \param mode     mode with which open file
//! \return         pointer to opened file (FILE*)
//! \note call assert if function cannot open file on the path filename
FILE* open_file(const char* filename, const char mode[]) {
    assert(filename != NULL);

    FILE* file = fopen(filename, mode);

    assert(file != NULL);

    return file;
}

//! Function defines size of file
//! \param filename path to file (absolute or relative)
//! \return         size of file (in bytes)
int file_size(const char* filename) {
    assert(filename != NULL);

    struct stat buff = {};
    stat(filename, &buff);

    return (int)buff.st_size;
}

//! Function reads strings from file
//! \param filename pointer to string of path to file
//! \return         object of Text structure
Text get_text_from_file(const char* filename) {
    assert(filename != NULL);

    FILE* file = open_file(filename, "r");

    int f_size = file_size(filename);

    char* data = (char*)calloc(f_size + 1, sizeof(char));
    int bytes = (int)fread(data, sizeof(char), f_size, file);
    f_size = f_size > bytes ? bytes : f_size;

    if (data[f_size - 1] != '\n') {
        data[f_size] = '\n';
        f_size++;
    } else {
        data[f_size] = '\1';
        f_size++;
    }

    Text text = {};
    text.data = data;
    text.data_size = f_size;
    text.lines = replace(data, f_size, '\n', '\0');

    text.text = (String*)calloc(text.lines, sizeof(String));
    load_string_pointers(&text);

    fclose(file);
    return text;
}

//! Function writes strings to file (from Text->text)
//! \param filename pointer to string of path to file (absolute or relative)
//! \param mode     mode with which open file
//! \param data     pointer to object of Text structure, where will strings come from
//! \return         number of written strings
int write_text_to_file(const char* filename, const char mode[], const struct Text* data) {
    assert(filename != NULL);
    assert(mode != NULL);
    assert(data != NULL);

    FILE* file = open_file(filename, mode);

    if (data->lines == 0) {
        fputs("", file);
        return 0;
    }

    int n_wr_strings = 0;
    for (n_wr_strings = 0; n_wr_strings < data->lines; n_wr_strings++) {
        fputs(data->text[n_wr_strings].ptr, file);
        fputs("\n", file);
    }

    fclose(file);
    return n_wr_strings;
}
//! Function writes strings to file (from Text->buffer)
//! \param filename pointer to string of path to file (absolute or relative)
//! \param mode     mode with which open file
//! \param data     pointer to object of Text structure, where will strings come from
//! \return         number of written strings
//! \note '\0' indicates line ending in buffer, so all lines in buffer must end in '\0'
int write_buffer_to_file(const char* filename, const char mode[], const struct Text* data) {
    assert(filename != NULL);
    assert(mode != NULL);
    assert(data != NULL);

    FILE* file = open_file(filename, mode);

    if (data->data_size == 0) {
        fputs("", file);
        return 0;
    }

    int n_wr_strings = 0;
    char* start_ptr = data->data;
    for (n_wr_strings = 0; n_wr_strings < data->lines; n_wr_strings++) {
        fputs(start_ptr, file);
        fputs("\n", file);

        char* end_ptr = strchr(start_ptr, '\0');
        start_ptr = end_ptr + 1;
    }

    fclose(file);
    return n_wr_strings;
}
//! Function writes strings to file (from array of char*)
//! \param filename  pointer to string of path to file (absolute or relative)
//! \param mode      mode with which open file
//! \param data      pointer to array of char*
//! \param n_strings number of elements in data
//! \return          number of written strings
int write_strings_to_file(const char* filename, const char mode[], const char** data, int n_strings) {
    assert(filename != NULL);
    assert(mode != NULL);
    assert(data != NULL);

    FILE* file = open_file(filename, mode);

    if (n_strings == 0) {
        fputs("", file);
        return 0;
    }

    int n_wr_strings = 0;
    for (n_wr_strings = 0; n_wr_strings < n_strings; n_wr_strings++) {
        fputs(data[n_wr_strings], file);
        fputs("\n", file);
    }

    fclose(file);
    return n_wr_strings;
}

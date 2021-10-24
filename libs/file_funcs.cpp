//
// Created by ivanbrekman on 26.08.2021.
//

#include <cstdio>
#include <cstdlib>
#include <cassert>

#include <cwchar>
#include <sys/stat.h>
#include <cstring>
#include <cctype>

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
    assert(VALID_PTR(string));

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
void print_text(const Text* data, const char* sep, const char* end) {
    assert(VALID_PTR(data));

    printf("[ ");
    for (int i = 0; i < data->lines; i++) {
        printf("\"%s\"", data->text[i].ptr);
        if (i + 1 < data->lines) printf("%s", sep);
    }
    printf(" ]%s", end);
}
//! Function prints array of strings
//! \param array pointer to array of strings
//! \param size  size of array
void print_strings(const char** array, size_t size, const char* sep, const char* end) {
    assert(VALID_PTR(array));

    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("\"%s\"", array[i]);
        if (i + 1 < size) printf("%s", sep);
    }
    printf(" ]%s", end);
}

//! Function load pointers of beginnings of strings to an array
//! \param text                    pointer to Text object, where string will be written
//! \param skip_empty_strings      flag to skip empty strings in text (default 0)
//! \param skip_first_last_spaces  flag to skip spaces before first letter and after last letter (default 0)
//! \return                        1
int load_string_pointers(Text* text, int skip_empty_strings, int skip_first_last_spaces) {
    assert(VALID_PTR(text->text));
    assert(VALID_PTR(text->data));

    int skiped_str = 0, letters_started = 0, spaces_count = 0;
    char* start_ptr = (char*)text->data;

    for (int i = 0, str_index = 0; i < text->data_size && str_index < text->lines; i++) {
        if (text->data[i] == '\0') {
            char* end_ptr = (char*)&(text->data[i]);

            if (spaces_count) {
                text->data[i - spaces_count] = '\0';
                end_ptr -= spaces_count;
                
                spaces_count = 0;
            }

            if (!letters_started) {
                start_ptr    += spaces_count;
                spaces_count  = 0;
            }

            struct String string = {
                    start_ptr,
                    (size_t)(end_ptr - start_ptr)
            };

            if (skip_empty_strings && string.len == 0) {
                skiped_str++;
            } else {
                text->text[str_index++] = string;
            }

            start_ptr = (char*)&(text->data[i + 1]);
            letters_started = 0;

            continue;
        }

        if (isspace(text->data[i])) {
            spaces_count++;
        }
        if (!isspace(text->data[i]) && !letters_started) {
            start_ptr += spaces_count;
            letters_started = 1;
        }
        if (!isspace(text->data[i])) {
            spaces_count = 0;
        }
    }

    text->lines -= skiped_str;

    return 1;
}
//! Function convert array of strings to Text
//! \param strings   ptr to array of strings
//! \param n_strings number of strings
//! \return          Text representation of array of strings
Text convert_to_text(const char** strings, int n_strings) {
    assert(VALID_PTR(strings));

    int sum_length = 0;
    int* lengths = (int*) calloc(n_strings, sizeof(int));
    for (int i = 0; i < n_strings; i++) {
        int length = (int) strlen(strings[i]) + 1;
        lengths[i] = length;
        sum_length += length;
    }

    char* data = (char*) calloc(sum_length, sizeof(char));
    int ptr = 0;
    for (int i = 0; i < n_strings; i++) {
        ptr += lengths[i];
        strcat(data, strings[i]);
        strcat(data, " ");
    }
    data[ptr] = '\0';

    Text text = {};
    text.data = data;
    text.data_size = ptr + 1;
    text.lines = replace(data, text.data_size, ' ', '\0');

    text.text = (String*)calloc(text.lines, sizeof(String));
    load_string_pointers(&text);

    return text;
}

//! Function defines size of file
//! \param filename path to file (absolute or relative)
//! \return         size of file (in bytes)
int  file_size       (const char* filename) {
    assert(VALID_PTR(filename));

    struct stat buff = {};
    stat(filename, &buff);

    return (int)buff.st_size;
}
//! Function defines last time of changes in file (with big accuracy)
//! \param  filename path to file (absolute or relative)
//! \return          time of last changes (in nanoseconds)
long file_last_change(const char* filename) {
    assert(VALID_PTR(filename));

    struct stat buff = {};
    stat(filename, &buff);

    return 1000000000 * buff.st_mtim.tv_sec + buff.st_mtim.tv_nsec;
}

//! Function opens file
//! \param filename path to file to open (absolute or relative)
//! \param mode     mode with which open file
//! \return         pointer to opened file (FILE*)
//! \note call assert if function cannot open file on the path filename
FILE* open_file(const char* filename, const char mode[]) {
    assert(VALID_PTR(filename));

    FILE* file = fopen(filename, mode);

    assert(VALID_PTR(file));

    return file;
}
//! Function reads strings from file
//! \param filename pointer to string of path to file
//! \return         object of Text structure
Text get_text_from_file(const char* filename, int skip_empty_strings, int skip_first_last_spaces) {
    assert(VALID_PTR(filename));

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
    load_string_pointers(&text, skip_empty_strings, skip_first_last_spaces);

    fclose(file);
    return text;
}

//! Function writes strings to file (from Text->text)
//! \param filename pointer to string of path to file (absolute or relative)
//! \param mode     mode with which open file
//! \param data     pointer to object of Text structure, where will strings come from
//! \param text_sep string which different Text strings will be separated
//! \return         number of written strings
int write_text_to_file(const char* filename, const char mode[], const Text* data, const char* text_sep) {
    assert(VALID_PTR(filename));
    assert(VALID_PTR(mode));
    assert(VALID_PTR(data));

    FILE* file = open_file(filename, mode);

    if (data->lines == 0) {
        fputs("", file);
        return 0;
    }

    int n_wr_strings = 0;
    for (n_wr_strings = 0; n_wr_strings < data->lines; n_wr_strings++) {
        fputs(data->text[n_wr_strings].ptr, file);
        if (n_wr_strings + 1 < data->lines) fputs(text_sep, file);
    }
    fputs("\n", file);

    fclose(file);
    return n_wr_strings;
}
//! Function writes strings to file (from Text->buffer)
//! \param filename pointer to string of path to file (absolute or relative)
//! \param mode     mode with which open file
//! \param data     pointer to object of Text structure, where will strings come from
//! \param buf_sep  string which different Text strings will be separated
//! \return         number of written strings
//! \note '\0' indicates line ending in buffer, so all lines in buffer must end in '\0'
int write_buffer_to_file(const char* filename, const char mode[], const struct Text* data, const char* buf_sep) {
    assert(VALID_PTR(filename));
    assert(VALID_PTR(mode));
    assert(VALID_PTR(data));

    FILE* file = open_file(filename, mode);

    if (data->data_size == 0) {
        fputs("", file);
        return 0;
    }

    int n_wr_strings = 0;
    char* start_ptr = data->data;
    for (n_wr_strings = 0; n_wr_strings < data->lines; n_wr_strings++) {
        fputs(start_ptr, file);
        if (n_wr_strings + 1 < data->lines) fputs(buf_sep, file);

        char* end_ptr = strchr(start_ptr, '\0');
        start_ptr = end_ptr + 1;
    }
    fputs("\n", file);

    fclose(file);
    return n_wr_strings;
}
//! Function writes strings to file (from array of char*)
//! \param filename  pointer to string of path to file (absolute or relative)
//! \param mode      mode with which open file
//! \param data      pointer to array of char*
//! \param n_strings number of elements in data
//! \param str_sep  string which different data strings will be separated
//! \return          number of written strings
int write_strings_to_file(const char* filename, const char mode[], const char** data, int n_strings, const char* str_sep) {
    assert(VALID_PTR(filename));
    assert(VALID_PTR(mode));
    assert(VALID_PTR(data));

    FILE* file = open_file(filename, mode);

    if (n_strings == 0) {
        fputs("", file);
        return 0;
    }

    int n_wr_strings = 0;
    for (n_wr_strings = 0; n_wr_strings < n_strings; n_wr_strings++) {
        fputs(data[n_wr_strings], file);
        if (n_wr_strings + 1 < n_strings) fputs(str_sep, file);
    }
    fputs("\n", file);

    fclose(file);
    return n_wr_strings;
}

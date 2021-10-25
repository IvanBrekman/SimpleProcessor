//
// Created by ivanbrekman on 24.10.2021.
//

#ifndef SIMPLEPROCESSOR_LABELS_H
#define SIMPLEPROCESSOR_LABELS_H

#include "helper.h"

struct Labels {
    int        labels[MAX_LABELS] = { };
    const char* names[MAX_LABELS] = { };

    int labels_count = 0;
};

int     labels_ctor(      Labels* lab);
int     labels_dtor(      Labels* lab);

int    print_labels(const Labels* lab);

int  get_lab_by_val(const Labels* lab, int val);
int get_lab_by_name(const Labels* lab, const char* name);
int   uniq_lab_name(const Labels* lab, const char* name);
int  possible_label(const Labels* lab,       char* string);

int     write_label(      Labels* lab, const char* name, int label);
int      read_label(const Labels* lab, const char* name);
int  can_read_label(const Labels* lab, const int index);

#endif //SIMPLEPROCESSOR_LABELS_H

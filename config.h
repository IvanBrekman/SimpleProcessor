//
// Created by ivanbrekman on 04.10.2021.
//

#ifndef SIMPLEPROCESSOR_CONFIG_H
#define SIMPLEPROCESSOR_CONFIG_H

struct header {
    char signature[3] = "IB";
    char version[10]  = "1.0.0";
};
const header HEADER = {};

#define VALIDATE_LEVEL  1
#define LOG_PRINTF      1
#define LOG_STACK_STATE 1

#define MAX_FILEPATH_SIZE 50

#endif //SIMPLEPROCESSOR_CONFIG_H

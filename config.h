//
// Created by ivanbrekman on 04.10.2021.
//

#ifndef SIMPLEPROCESSOR_CONFIG_H
#define SIMPLEPROCESSOR_CONFIG_H

struct header {
    char signature[3] = "IB";
    char version[10]  = "1.1.1";
};
const header HEADER = { };

#define MAX_FILEPATH_SIZE 50
#define MAX_ARG_SIZE      50

#define VALIDATE_LEVEL      1
#define LOG_PRINTF          1
#define LOG_PROCESSOR_STATE 0

#define SKIP_EMPTY_STRINGS      1
#define SKIP_FISRT_LAST_SPACES  1

#define COMMENT_SYMBOL '#'
#define SLEEP 0

#endif //SIMPLEPROCESSOR_CONFIG_H

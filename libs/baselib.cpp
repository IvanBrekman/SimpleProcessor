//
// Created by ivanbrekman on 06.10.2021.
//

#include <ctime>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>

int isbadreadptr(void* ptr) {
    int nullfd = open("/dev/random", O_WRONLY);

    errno = 0;
    write(nullfd, ptr, 1);
    close(nullfd);

    return errno;
}
char* datetime(char* calendar_date) {
    const time_t timer = time(NULL);
    struct tm* calendar = localtime(&timer);

    strftime(calendar_date, 40, "%d.%m.%Y %H:%M:%S, %A", calendar);

    return calendar_date;
}

int is_number(char* string) {
    int res = atoi(string);

    if (res == 0) {
        return string[0] == '0' && string[1] == '\0';
    }
    return 1;
}
int digits_number(int number, int radix) {
    int digits = 0;
    while (number > 0) {
        number /= radix;
        digits++;
    }

    return digits;
}

int extract_bit(int number, int bit) {
    printf("number: %d\n"
           "bit %d: %d\n", number, bit, (number >> bit) & 1);
    return (number >> bit) & 1;
}
char* to_string(int number) {
    int d_num = digits_number(number, 10);
    char* str_num = (char*) calloc(d_num + 1, sizeof(char));

    for (int i = d_num - 1; number > 0; i--) {
        str_num[i] = '0' + (number % 10);
        number /= 10;
    }
    str_num[d_num] = '\0';

    return str_num;
}

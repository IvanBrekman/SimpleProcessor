//
// Created by ivanbrekman on 06.10.2021.
//

#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>

#include "baselib.h"

//! Function checks validity of pointer
//! \param  ptr checking pointer
//! \return 0 if all is good, else != 0
int isbadreadptr(const void* ptr) {
    int nullfd = open("/dev/random", O_WRONLY);

    errno = 0;
    write(nullfd, ptr, 1);
    close(nullfd);

    return errno;
}

//! Function writes current date and time to calendar_date
//! \param calendar_date ptr to string, where current date and time will bw written
//! \return              ptr to calendar_date
char* datetime(char* calendar_date) {
    assert(VALID_PTR(calendar_date) && "Invalid calendar_date ptr");

    const time_t timer = time(NULL);
    struct tm* calendar = localtime(&timer);

    strftime(calendar_date, 40, "%d.%m.%Y %H:%M:%S, %A", calendar);

    return calendar_date;
}

//! Function checks if string can be int
//! \param string checking string
//! \return       1 if string can be int, else 0
int is_number(char* string) {
    assert(VALID_PTR(string) && "Invalid string ptr");

    int res = atoi(string);

    if (res == 0) {
        return string[0] == '0' && string[1] == '\0';
    }
    return 1;
}

//! Function count digits in number in radix number system
//! \param number number
//! \param radix  number system (default 10)
//! \return       number of digits
int digits_number(int number, int radix) {
    assert(radix > 1 && "Incorrect radix value");

    int digits = 0;
    while (number > 0) {
        number /= radix;
        digits++;
    }

    return digits;
}

//! Function extracts bit from number
//! \param number number
//! \param bit    number of bit
//! \return bit-th bit of number
int extract_bit(int number, int bit) {
    assert(bit >= 0 && "Incorrect bit number");

    return (number >> bit) & 1;
}

//! Function convert 4-bytes number to bin view
//! \param number converting number
//! \return       converted to bin view number as string
char* bin4(int number) {
    char* bits = (char*) calloc(32, sizeof(char));
    int real_bits = 0;

    while (number > 0) {
        bits[real_bits++] = (char)('0' + (number % 2));
        number /= 2;
    }

    for (int i = 0; i < real_bits / 2; i++) {
        char tmp = bits[i];
        bits[i] = bits[real_bits - 1 - i];
        bits[real_bits - 1 - i] = tmp;
    }

    bits[real_bits] = '\0';
    return bits;
}

//! Function convert number to string
//! \param number converting number
//! \return       converted number
const char* to_string(int number) {
    if (number == 0) {
        return "0";
    }

    int d_num = digits_number(number, 10);
    char* str_num = (char*) calloc(d_num + 1, sizeof(char));

    for (int i = d_num - 1; number > 0; i--) {
        str_num[i] = (char)('0' + (number % 10));
        number /= 10;
    }
    str_num[d_num] = '\0';

    return (const char*) str_num;
}

//! Function compares to int  values
//! \param num1 ptr to first  value
//! \param num2 ptr to second value
//! \return (< 0) if (num1 < num2), 0 if (num1 == num2), (>0) if (num1 > num2)
int cmp_int(const void* num1, const void* num2) {
    assert(VALID_PTR(num1) && "Invalid num1 ptr");
    assert(VALID_PTR(num2) && "Invalid num2 ptr");
    
    return *(const int*)num1 - *(const int*)num2;
}

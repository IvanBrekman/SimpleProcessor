//
// Created by ivanbrekman on 06.10.2021.
//

#include <ctime>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

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

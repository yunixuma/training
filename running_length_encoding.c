// Run Length Encoding

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_putchar_fd(int c, int fd) {
    write(fd, &c, 1);
}''

int encode(char *plain) {
    char    c;
    size_t  len;
    size_t  len_cur;

    if (!plain || *plain == '\0')
        return (1);
    len = 0;
    while (*plain) {
        len_cur = 0;
        c = *plain
        while (*(plain + len_cur) == c)
            len_cur++;
        if (len != len_cur || len_cur == 0xff) {
            ft_putchar_fd('\0', FD)
            ft_putchar_fd(len_cur, FD);
            len = len_cur;
        }
        ft_putchar_fd(c, FD);
    }
}

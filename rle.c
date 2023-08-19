// Run Length Encoding

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define FD  1

static void    ft_putchar_fd(int c, int fd) {
    write(fd, &c, 1);
}

/*
static size_t   ft_strlen(char *s) {
    char    *s_head;

    if (!s)
        return (0);
    s_head = s;
    while (*s)
        s++;
    return (s - s_head);
}

static void    ft_putstr_fd(char *s, int fd) {
    if (!s)
        return ;
    write(fd, s, ft_strlen(s));
}
*/

int rle(char *plain) {
    char    c;
    size_t  len;
    size_t  len_cur;

    if (!plain || *plain == '\0')
        return (1);
    len = 0;
    while (*plain) {
        len_cur = 0;
        c = *plain;
        while (*(plain + len_cur) == c)
            len_cur++;
        if (len != len_cur || len_cur == 0xff) {
            ft_putchar_fd('\0', FD);
            ft_putchar_fd(len_cur, FD);
            len = len_cur;
        }
        ft_putchar_fd(c, FD);
        plain += len;
    }
    ft_putchar_fd('\0', FD);
    ft_putchar_fd('\0', FD);
    return (0);
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        return (2);
    rle(argv[1]);
    return (0);
}
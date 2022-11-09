#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    while (*s)
        ft_putchat_fd(*s++, fd);
}
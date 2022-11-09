#include "libft.h"

char *ft_memchr(const void *s, int c, size_t n)
{
    int i;

    if (!s)
        return (0);
    i = 0;
    while (i < n)
    {
        if ((unsigned char)c == *(unsigned char *)(s + i))
            return ((void *)(s + i));
        i++;
    }
    return (0);
}

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    int i;

    if (!s)
        return (0);
    i = 0;
    while (i < n)
    {
        *(unsigned char*)(s + i) = (unsigned char)c;
        i++;
    }
    return (s);
}


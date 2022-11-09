#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    int i;

    if (!s)
        return (0);
    i = 0;
    while (i < n)
    {
        *(unsigned char*)(s + i) = '\0';
        i++;
    }
}

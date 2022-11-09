#include "libft.h"

void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    int i;

    if (!dest)
        return (0);
    i = 0;
    while (i < n)
    {
        *(char *)(dest + i) = *(char *)(src + i);
        i++;
    }
    return (dest);
}

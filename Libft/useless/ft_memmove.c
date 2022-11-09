#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    int i;
    int step;

    if (!dest || !src)
        return (0);
    if (dest > src)
    {
        step = -1;
        i = (int)n - 1;
    }   
    else
    {
        step = 1;
        i = 0;
    }
    while ((step == 1 && i < (int)n) || (step == -1 && i >= 0))
    {
        *(char *)(dest + i) = *(char *)(src + i);
        i += step;
    }
    return (dest);
}

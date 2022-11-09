#include "libft.h"

void *calloc(size_t nmemb, size_t size)
{
    void *dest;

    dest = (void *)malloc(size * nmemb);
    if (!dest)
        return (0);
    ft_bzero(dest, nmemb);
    return (dest);
}
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t  len;
    size_t  i;
    char    *res;

    res = ft_strdup(s);
    if (!res)
        return (0);
    i = 0;
    while (i < len)
        res[i] = (*f)(i, s[i++]);
    return (res);
}
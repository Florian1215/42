#include "libft.h"

int ft_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

int ft_tolower(int c)
{
    if (ft_isupper(c))
        return (c + ('a' - 'A'));
    return (c);
}

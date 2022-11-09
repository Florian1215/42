#include "libft.h"

int ft_islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

int ft_toupper(int c)
{
    if (ft_islower(c))
        return (c + ('A' - 'a'));
    return (c);
}

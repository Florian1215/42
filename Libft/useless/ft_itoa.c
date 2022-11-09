#include "libft.h"

int	ft_nblen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char    *ft_itoa(int n)
{
	char	*res;
	int		len;
    unsigned    nb;

    if (n < 0)
        nb = -n;
    else
        nb = n;
    len = ft_nblen(nb) + (n == 0) + (n < 0);
    
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (nb % 10) + '0';
		nb /= 10;
	}
    if (n < 0)
        res[++len] = '-';
	return (res);
}

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < n && *dest)
		dest++;
	if (i == n)
		return (i + (unsigned int)ft_strlen(src));
	j = -1;
	while (src[++j])
		if (j < n - i - 1)
			*dest++ = src[j];
	*dest = '\0';
	return (i + j);
}

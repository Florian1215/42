#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
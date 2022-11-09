int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -sign;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}
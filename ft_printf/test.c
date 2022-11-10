
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putunb(unsigned long int nb)
{
	if (nb >= 10)
	{
		ft_putunb(nb / 10);
		nb %= 10;
	}
	ft_putchar(nb + '0');
}

void	ft_putnbr_base(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	ft_putunb(nb);
}

void	ft_putnbr_dec(float n)
{
	ft_putnbr_base(n);
	n *= 10;
	ft_putchar('.');
	while ((int)n % 10)
	{
		ft_putchar((int)n % 10 + '0');
		n *= 10;
		printf("\nn = %f\n", n);
		scanf("%d");
	}
}

int	main(void)
{
	printf("printf = %f\n", 3.5);
	ft_putnbr_dec(3.5884845);
	return (0);
}

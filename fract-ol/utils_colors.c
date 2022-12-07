#include "fractol.h"

int	get_gradient(double c1, double c2, double r)
{
	int		color;
	double	rgb1;
	double	rgb2;
	int		i;

	i = 0;
	color = 0;
	while (i < 3)
	{
		rgb1 = ((int)c1 >> i * 8) & 255;
		rgb2 = ((int)c2 >> i * 8) & 255;
		color |= (int)((rgb2 - rgb1) * r + rgb1) << i * 8;
		i++;
	}
	return (color);
}
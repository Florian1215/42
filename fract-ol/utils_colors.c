/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:49:37 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/10 10:49:38 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_gradient(double r, int c1, int c2)
{
	t_co	rgb;
	int		res;
	int		i;

	res = 0;
	i = -1;
	while (++i < 3)
	{
		rgb = init_coor((c1 >> i * 8) & 255, (c2 >> i * 8) & 255);
		res |= (int)((rgb.y - rgb.x) * r + rgb.x) << i * 8;
	}
	return (res);
}

int	get_color(t_color color, double r, int dark_mode)
{
	int	c1;
	int	c2;
	int	fg;

	fg = 0x222222;
	if (r >= 1)
		return (fg);
	else if (r >= 0.6)
	{
		c1 = color.c2;
		c2 = color.c1;
	}
	else
	{
		if (dark_mode)
			c1 = fg;
		else
			c1 = color.c3;
		c2 = color.c2;
	}
	return (get_gradient(r, c1, c2));
}

void	set_color(t_mlx *mlx, t_colors color)
{
	void	(*colors_set[5])();

	colors_set[0] = set_1;
	colors_set[1] = set_2;
	colors_set[2] = set_3;
	colors_set[3] = set_4;
	colors_set[4] = set_5;
	mlx->fractal.color = color;
	if (mlx->fractal.color == 5)
		mlx->fractal.color = 0;
	colors_set[mlx->fractal.color](mlx);
	if (!mlx->in_menu)
		fractal_render(mlx);
}

t_color	init_color( int c1, int c2, int c3, t_colors set)
{
	t_color	color;

	color.c1 = c1;
	color.c2 = c2;
	color.c3 = c3;
	color.set = set;
	return (color);
}

void	toggle_dark_mode(t_mlx *mlx)
{
	mlx->dark_mode = !mlx->dark_mode;
	if (mlx->in_menu)
		set_menu(mlx);
	else
		fractal_render(mlx);
}

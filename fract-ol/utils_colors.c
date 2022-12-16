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

static int	get_gradient(double r, union u_color c1, union u_color c2)
{
	union u_color	res;

	res.rgb.r = (int)((c2.rgb.r - c1.rgb.r) * r + c1.rgb.r);
	res.rgb.g = (int)((c2.rgb.g - c1.rgb.g) * r + c1.rgb.g);
	res.rgb.b = (int)((c2.rgb.b - c1.rgb.b) * r + c1.rgb.b);
	return (res.color);
}

int	get_color(t_colors set, double r, int dark_mode)
{
	static t_color	(*colors_set[5])() = {set_1, set_2, set_3, set_4, set_5};
	union u_color	c1;
	union u_color	c2;
	union u_color	fg;
	t_color			color;

	color = colors_set[set]();
	fg.color = 0x222222;
	if (r >= 1)
		return (fg.color);
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
	mlx->fractal.color = color;
	if (mlx->fractal.color == 5)
		mlx->fractal.color = 0;
	if (!mlx->in_menu)
		fractal_render(mlx);
}

t_color	init_color(t_colors set, int c1, int c2, int c3)
{
	t_color	color;

	color.c1.color = c1;
	color.c2.color = c2;
	color.c3.color = c3;
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

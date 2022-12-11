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

int	get_gradient(t_mlx *mlx, double r)
{
	int		color;
	double	rgb1;
	double	rgb2;
	int		i;

	if (r == 1)
		return (mlx->color.bg);
	i = 0;
	color = 0;
	while (i < 3)
	{
		rgb1 = (mlx->color.c1 >> i * 8) & 255;
		rgb2 = (mlx->color.c2 >> i * 8) & 255;
		color |= (int)((rgb2 - rgb1) * r + rgb1) << i * 8;
		i++;
	}
	return (color);
}

void	set_color(t_mlx *mlx, int new)
{
	void	(*colors_set[5])() = { set_1, set_2, set_3, set_4, set_5 };

	if (new)
		mlx->color_set++;
	if (mlx->color_set == 5)
		mlx->color_set = 0;
	colors_set[mlx->color_set](mlx);
	if (new && !mlx->in_menu)
		fractol(mlx);
}

t_color	init_color(int fg, int bg, int c1, int c2)
{
	t_color	color;

	color.fg = fg;
	color.bg = bg;
	color.c1 = c1;
	color.c2 = c2;
	return (color);
}

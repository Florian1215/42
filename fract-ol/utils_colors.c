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

static int	get_gradient(t_palette pal, double i, int color, int cat)
{
	t_color	col;

	col.rgb.r = pal.colors[color].rgb.r + ((pal.colors[color + 1].rgb.r - pal.colors[color].rgb.r) * ((i - cat * color) / cat));
	col.rgb.g = pal.colors[color].rgb.g + ((pal.colors[color + 1].rgb.g - pal.colors[color].rgb.g) * ((i - cat * color) / cat));
	col.rgb.b = pal.colors[color].rgb.b + ((pal.colors[color + 1].rgb.b - pal.colors[color].rgb.b) * ((i - cat * color) / cat));
	return (col.color);
}

int	get_color(t_mlx *mlx, int i, double sqr, t_colors set)
{
	static t_palette	(*colors_set[10])() = {set_1, set_2, set_3, set_4, \
			set_5, set_6, set_7, set_8, set_9, set_10};
	double				fact;
	int					color;
	int					cat;

	fact = 1 + ((log(log(2)) - log((0.5 * log(sqr)))) / log(2));
	if (fact > 0.9999)
		fact = 0.9999;
	if (fact < 0)
		fact = 0;
	fact += i;
	cat = (mlx->max_iter / 4);
	if (!cat)
		cat = 1;
	color = i / cat;
	if (color < 0)
		color = 0;
	return (get_gradient(colors_set[set](), fact, color, cat));
}

void	set_color(t_mlx *mlx, t_colors color)
{
	mlx->fractal.color = color;
	if (mlx->fractal.color == 5)
		mlx->fractal.color = 0;
	if (!mlx->in_menu)
		fractal_render(mlx);
}

void	toggle_dark_mode(t_mlx *mlx)
{
	mlx->dark_mode = !mlx->dark_mode;
	if (mlx->in_menu)
		set_menu(mlx);
	else
		fractal_render(mlx);
}

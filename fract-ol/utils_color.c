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

static int	get_gradient(t_color *pal, int color, double op, int cat)
{
	t_color			col;

	col.rgb.r = pal[color].rgb.r + ((pal[color + 1].rgb.r - pal[color].rgb.r) * ((op - cat * color) / cat));
	col.rgb.g = pal[color].rgb.g + ((pal[color + 1].rgb.g - pal[color].rgb.g) * ((op - cat * color) / cat));
	col.rgb.b = pal[color].rgb.b + ((pal[color + 1].rgb.b - pal[color].rgb.b) * ((op - cat * color) / cat));
	return (col.color);
}

int	get_color(t_mlx *mlx, t_fractal frac, int i, double sqr)
{
	static t_color	*(*colors_set[12])(t_appearance app) = {set_green, \
	set_purple, set_electric_blue, set_red, set_blue_red, set_pink, \
	set_green_blue, set_blue_light, set_pastel_pink, set_night_blue, \
	set_blue, set_yellow};
	t_colors		set;
	double			op;
	int				color;
	int				cat;

	op = 1 + ((log(log(2)) - log((0.5 * log(sqr)))) / log(2));
	if (op > 0.9999)
		op = 0.9999;
	if (op < 0)
		op = 0;
	op += i;
	cat = frac.max_iter / 4;
	if (!cat)
		cat = 1;
	color = i / cat;
	if (color < 0)
		color = 0;
	if (mlx->in_menu)
		set = frac.color;
	else
		set = mlx->color;
	return (get_gradient(colors_set[set](mlx->appearance), color, op, cat));
}

void	edit_color(t_mlx *mlx)
{
	mlx->offset_color = (mlx->offset_color + 1) % 12;
	if (mlx->in_menu)
		set_menu(mlx);
	else
		set_color(mlx, mlx->fractal.color);
}

void	set_color(t_mlx *mlx, t_colors color)
{
	mlx->color = (color + mlx->offset_color) % 12;
	if (!mlx->in_menu && !mlx->c_animate)
		fractal_render(mlx);
}

void	toggle_appearance(t_mlx *mlx)
{
	mlx->appearance = !mlx->appearance;
	if (mlx->in_menu)
		set_menu(mlx);
	else
		fractal_render(mlx);
}

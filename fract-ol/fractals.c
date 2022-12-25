/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:49:33 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/10 10:49:34 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_mlx *mlx, t_co c, t_colors color_set)
{
	t_co	z;
	int		i;
	t_co	sqr;

	z = init_coor(mlx->c.x, mlx->c.y);
	sqr = init_coor(pow(z.x, 2), pow(z.y, 2));
	i = -1;
	while (++i < mlx->max_iter)
	{
		z.y = 2 * z.x * z.y + c.y;
		z.x = sqr.x - sqr.y + c.x;
		sqr = init_coor(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, i, sqr.x + sqr.y, color_set));
	}
	return (FG);
}

int	julia(t_mlx *mlx, t_co z, t_colors color_set)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_coor(pow(z.x, 2), pow(z.y, 2));
	while (++i < mlx->max_iter)
	{
//		z.y = 2 * z.x * z.y - mlx->c.y;
//		z.x = sqr.x - sqr.y - (mlx->in_menu ? 1 : mlx->c.x);
		z.x = z.x * z.x * z.x - 3 * z.y * z.y * z.x + mlx->c.x;
		z.y = -z.y * z.y * z.y + 3 * sqr.x * z.y + mlx->c.y;
		sqr = init_coor(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, i, sqr.x + sqr.y, color_set));
	}
	return (FG);
}

int	burning_shipe(t_mlx *mlx, t_co c, t_colors color_set)
{
	t_co	z;
	t_co	sqr;
	int		i;

	z = init_coor(mlx->c.x, mlx->c.y);
	sqr = init_coor(pow(z.x, 2), pow(z.y, 2));
	i = -1;
	while (++i < mlx->max_iter)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = sqr.x - sqr.y + c.x;
		sqr = init_coor(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, i, sqr.x + sqr.y, color_set));
	}
	return (FG);
}

int	celtic(t_mlx *mlx, t_co c, t_colors color_set)
{
	int		i;
	t_co	z;
	t_co	sqr;

	i = -1;
	z = init_coor(c.x, c.y);
	sqr = init_coor(pow(z.x, 2), pow(z.y, 2));
	while (++i < mlx->max_iter)
	{
		z.y = (2 * z.x * z.y) + c.x;
		z.x = fabs(sqr.x - sqr.y) + c.y;
		sqr = init_coor(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, i, sqr.x + sqr.y, color_set));
	}
	return (FG);
}

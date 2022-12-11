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

float	mandelbrot(t_mlx *mlx, t_co c)
{
	double	tmp;
	t_co	z;
	int		i;

	z = init_coor(0, 0);
	i = -1;
	while (++i < mlx->max_iter && z.x * z.x + z.y * z.y < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * tmp * z.y + c.y;
	}
	return ((float)i / mlx->max_iter);
}

float	julia(t_mlx *mlx, t_co z)
{
	double	tmp;
	int		i;
	double	j;

	i = -1;
	j = 1;
	while (++i < mlx->max_iter && z.x * z.x + z.y * z.y < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y - j;
		z.y = 2 * tmp * z.y;
	}
	return ((float)i / mlx->max_iter);
}

float	burning_shipe(t_mlx *mlx, t_co c)
{
	double	tmp;
	t_co	z;
	int		i;

	z = init_coor(0, 0);
	i = -1;
	while (++i < mlx->max_iter && z.x * z.x + z.y * z.y < 4)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * tmp * z.y + c.y;
	}
	return ((float)i / mlx->max_iter);
}

float	celtic(t_mlx *mlx, t_co c)
{
	int		i;
	t_co	z;
	t_co	sqr;

	i = 0;
	z = init_coor(0, 0);
	sqr = init_coor(0, 0);
	while (i < mlx->max_iter && sqr.x + sqr.y < 4)
	{
		z.y = (2 * z.x * z.y) + c.x;
		z.x = fabs(sqr.x - sqr.y) + c.y;
		sqr.x = pow(z.x, 2);
		sqr.y = pow(z.y, 2);
		i++;
	}
	return ((float)i / mlx->max_iter);
}

void	fractol(t_mlx *mlx)
{
	t_co	i;
	double	color;
	float	res;
	t_co	r;

	i.x = -1;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	r = init_coor(
			(mlx->zoom.end.x - mlx->zoom.start.x) / (mlx->size.x - 1),
			(mlx->zoom.end.y - mlx->zoom.start.y) / (mlx->size.y - 1));
	while (++i.x < mlx->size.x)
	{
		i.y = -1;
		while (++i.y < mlx->size.y)
		{
			res = mlx->fractol(mlx, init_coor(mlx->zoom.start.x + i.x * r.x, mlx->zoom.end.y - i.y * r.y));
			color = get_gradient(mlx, res);
			mlx_put_pixel_img(&mlx->img, i, color);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}

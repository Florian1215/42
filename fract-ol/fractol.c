/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:36:42 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/05 14:48:22 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Ensemble Julia

1. Z**2 - 1
		tmp = zx;
		zx = zx * zx - zy * zy - j;
		zy = 2 * tmp * zy;
		if (zx * zx + zy * zy > 4)
			break ;
		i++;



*/

void	put_pixel(t_mlx *mlx, double x, double y, double j)
{
	double	tmp;
	(void)j;
	double	max_iter = 100;
	double	i = 0;
	int		color;

	double	cx = ((x - ((double)mlx->size_x / 2) + mlx->zoom_x) / ((double)mlx->size_x / 2)) * ((double)mlx->zoom / 100);
	double	cy = ((y - ((double)mlx->size_y / 2) + mlx->zoom_y) / ((double)mlx->size_y / 2)) * ((double)mlx->zoom / 100);

	double	zx = 0;
	double	zy = 0;
	/*if (x == 0 && y == 0)
		printf("0 - 0 | x = %f - y = %f\n", zx, zy);
	if (x == 999 && y == 999)
		printf("1000 - 1000 | x = %f - y = %f\n\n", zx, zy);*/
	while (i < max_iter)
	{
		tmp = zx;
		zx = zx * zx - zy * zy + cx;
		zy = 2 * tmp * zy + cy;
		if (zx * zx + zy * zy > 4)
			break ;
		i++;
	}
	if (i == max_iter)
		color = 0x222222;
	else// if (i > 3)
		color = get_gradient(0x3d663d, 0xa4be7b, i / max_iter * 20);
	//else
	//	color = 0x222222;
	fast_mlx_pixel_put(&mlx->img, x, y, color);
}

void	fractol(t_mlx *mlx, double j)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	while (ix < mlx->size_x)
	{
		iy = 0;
		while (iy < mlx->size_x)
			put_pixel(mlx, ix, iy++, j);
		ix++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}

void	move(t_mlx *mlx, int mv_x, int mv_y)
{
	mlx->zoom_x += mv_x;
	mlx->zoom_y += mv_y;
	fractol(mlx, 1);
}

void	zoom(t_mlx *mlx, int zoom_size, unsigned int x, unsigned int y)
{
	mlx->zoom += zoom_size;
	if (x)
		mlx->zoom_x = mlx->size_x / 2 - x;
	if (y)
		mlx->zoom_y = mlx->size_y / 2 - y;
	fractol(mlx, 1);
}

void	limit_zoom(t_mlx *mlx, int zoom_size, unsigned int x, unsigned int y)
{
	unsigned int nx;
	unsigned int ny;

	if (x > 700)
		nx = -50;
	else if (x < 300)
		nx = 50;
	else
		nx = 0;

	if (y > 700)
		ny = -50;
	else if (y < 300)
		ny = 50;
	else
		ny = 0;

	zoom(mlx, zoom_size, nx, ny);
}

int mouse_event(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4 && mlx->zoom < 5000)
		limit_zoom(mlx, -20, x, y);
	else if (button == 5 && mlx->zoom > 0)
		limit_zoom(mlx, 20, x, y);
	return (1);
}

int	key_event(int k, t_mlx *mlx)
{
	double	j;

	if (k == 53)
		close(mlx);
	else if (k == 12)
		zoom(mlx, (mlx->zoom - 100) * -1, mlx->size_x / 2, mlx->size_y / 2);
	else if (k == 1)
		zoom(mlx, 20, 0, 0);
	else if (k == 13)
		zoom(mlx, -20, 0, 0);
	else if (k == 123)
		move(mlx, -30, 0);
	else if (k == 124)
		move(mlx, 30, 0);
	else if (k == 125)
		move(mlx, 0, 30);
	else if (k == 126)
		move(mlx, 0, -30);
	else if (k == 38)
	{
		j = 0.5;
		while (j < 1.5)
		{
			printf("j = %f\n", j);
			fractol(mlx, j);
			j += 0.1;
		}
	}
	else
		printf("Key presse %d - %d\n", k, mlx->size_x);
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	(void)ac;
	(void)av;
	init_mlx(&mlx);
	if (!mlx)
		return (1);
	fractol(mlx, 1);
	mlx_key_hook(mlx->win_ptr, key_event, mlx);
	mlx_hook(mlx->win_ptr, 17, 0L, close, mlx);
	mlx_hook(mlx->win_ptr, 4, (1L<<2), mouse_event, mlx);
	mlx_loop(mlx->mlx_ptr);
}

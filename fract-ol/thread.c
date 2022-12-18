/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:30:55 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/14 15:30:56 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_render(t_mlx *mlx)
{
	int			i;
	t_thread	t[8];

	if (mlx->render)
		return ;
	mlx->render = 1;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	i = -1;
	while (++i < 8)
	{
		t[i].id = i;
		t[i].mlx = mlx;
		pthread_create(&t[i].thread, NULL, (void *)create_fractal, &t[i]);
	}
	i = -1;
	while (++i < 8)
		pthread_join(t[i].thread, NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	mlx->render = 0;
}

void	create_fractal(t_thread	*t)
{
	t_co	i;
	t_co	r;
	double	res;

	i.x = t->mlx->size.x / 8 * t->id - 1;
	r = init_coor(
			(t->mlx->fractal.end.x - t->mlx->fractal.start.x) / (t->mlx->size.x - 1),
			(t->mlx->fractal.end.y - t->mlx->fractal.start.y) / (t->mlx->size.y - 1));
	while (++i.x < t->mlx->size.x / 8 * (t->id + 1))
	{
		i.y = -1;
		while (++i.y < t->mlx->size.y)
		{
			res = (double)t->mlx->fractal.func(t->mlx, init_coor(t->mlx->fractal.start.x + i.x * r.x, t->mlx->fractal.end.y - i.y * r.y)) / (int)t->mlx->max_iter;
			mlx_put_pixel_img(&t->mlx->img, i, get_color(t->mlx->fractal.color, res, t->mlx->dark_mode));
		}
	}
}
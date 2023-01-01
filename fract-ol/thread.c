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
}

void	create_fractal(t_thread	*t)
{
	t_co	i;
	t_co	r;
	double	col;

	i.x = t->mlx->size / 8 * t->id - 1;
	r = init_complex(
			(t->mlx->fractal.end.x - t->mlx->fractal.start.x) / (t->mlx->size - 1),
			(t->mlx->fractal.end.y - t->mlx->fractal.start.y) / (t->mlx->size - 1));
	while (++i.x < t->mlx->size / 8 * (t->id + 1))
	{
		i.y = -1;
		while (++i.y < t->mlx->size)
		{
			col = t->mlx->fractal.func(t->mlx, t->mlx->fractal, init_complex(t->mlx->fractal.start.x + i.x * r.x, t->mlx->fractal.end.y - i.y * r.y));
			mlx_put_pixel_img(&t->mlx->img, i, col);
		}
	}
}

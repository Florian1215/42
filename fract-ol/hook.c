/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:49:38 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/10 10:49:39 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_event(int button, int x, int y, t_mlx *mlx)
{
	t_co	co;

	if (button == SCROLL_IN || button == SCROLL_OUT)
	{
		co = init_coor(
				(double)x / (mlx->size.x / (mlx->zoom.end.x - mlx->zoom.start.x)) + mlx->zoom.start.x,
				(double)y / (mlx->size.y / (mlx->zoom.end.y - mlx->zoom.start.y)) * -1 + mlx->zoom.end.y
				);
		if (button == SCROLL_IN)
			zoom(mlx, 1 / mlx->zoom.scale, co);
		else
			zoom(mlx, mlx->zoom.scale, co);
	}
	else if (button == LEFT_CLICK)
		select_menu(mlx, init_coor(x, y));
	else
		printf("mouse = %d\n", button);
	return (1);
}

int	key_event(int k, t_mlx *mlx)
{
	double	j;

	if (k == ESQ)
		close(mlx);
	else if (k == Q)
	{
		init_zoom(mlx);
		fractol(mlx);
	}
	else if (k == S)
		zoom(mlx, mlx->zoom.scale, init_coor(0, 0));
	else if (k == W)
		zoom(mlx, 1 / mlx->zoom.scale, init_coor(0, 0));
	else if (k == C)
		set_color(mlx, 1);
	else if (k == RIGHT)
		move(mlx, RIGHT);
	else if (k == LEFT)
		move(mlx, LEFT);
	else if (k == DOWN)
		move(mlx, DOWN);
	else if (k == UP)
		move(mlx, UP);
	else if (k == PLUS)
		edit_iter(mlx, 10);
	else if (k == MINUS)
		edit_iter(mlx, -10);
	else if (k == J)
	{
		j = 0.5;
		while (j < 1.5)
		{
			printf("f = %f - lf = %lf - Lf = %lf\n", j, j, j);
			fractol(mlx);
			j += 0.1;
		}
	}
	else
		printf("Key presse %d\n", k);
	return (1);
}

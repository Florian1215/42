/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:22:44 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:45 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractals	select_fractal(t_mlx *mlx, t_co co)
{
	t_co	size_half;

	if (co.x > mlx->size.x || co.y > mlx->size.y || co.x < 0 || co.y < 0)
		return (-1);
	size_half = init_coor(mlx->size.x / 2, mlx->size.y / 2);
	if (co.x < size_half.x && co.y < size_half.y)
		return (MANDELBROT);
	else if (co.x > size_half.x && co.y < size_half.y)
		return (JULIA);
	else if (co.x < size_half.x && co.y > size_half.y)
		return (CELTIC);
	else if (co.x > size_half.x && co.y > size_half.y)
		return (BURNING_SHIP);
	return (-1);
}

int	mouse_event_motion(int x, int y, t_mlx *mlx)
{
	t_fractals	current;
	t_co		co;

	if (mlx->in_menu)
	{
		current = select_fractal(mlx, init_coor(x, y));
		if (current != mlx->hover.set)
		{
			mlx->prev_hover = mlx->hover;
			mlx->hover.set = current;
			mlx->hover.value = 1;
			set_menu(mlx);
		}
	}
	else if (mlx->moving)
	{
		co.x = (mlx->prev_pos.x - x) / mlx->size.x * fabs(mlx->fractal.end.x - mlx->fractal.start.x);
		mlx->fractal.start.x += co.x;
		mlx->fractal.end.x += co.x;
		co.y = (mlx->fractal.set > 1 ? (mlx->prev_pos.y - y) : (y - mlx->prev_pos.y)) / mlx->size.y * fabs(mlx->fractal.end.y - mlx->fractal.start.y);
		mlx->fractal.start.y += co.y;
		mlx->fractal.end.y += co.y;
		fractal_render(mlx);
		mlx->prev_pos = init_coor(x, y);
	}
	return (1);
}

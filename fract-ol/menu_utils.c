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

t_slots	select_fractal(t_mlx *mlx, t_co co)
{
	int	size;

	if (co.x > mlx->size || co.y > mlx->size || co.x < 0 || co.y < 0)
		return (-1);
	size = mlx->size / 2;
	if (co.x < size && co.y < size)
		return (SLOT_1);
	else if (co.x > size && co.y < size)
		return (SLOT_2);
	else if (co.x < size && co.y > size)
		return (SLOT_3);
	else
		return (SLOT_4);
}

int	mouse_event_motion(int x, int y, t_mlx *mlx)
{
	t_fractals	current;
	t_co		co;

	if (mlx->in_menu)
	{
		current = (t_fractals)select_fractal(mlx, init_complex(x, y));
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
		co.x = (mlx->prev_pos.x - x) / mlx->size * fabs(mlx->fractal.end.x - mlx->fractal.start.x);
		mlx->fractal.start.x += co.x;
		mlx->fractal.end.x += co.x;
		co.y = (mlx->fractal.set > 1 ? (mlx->prev_pos.y - y) : (y - mlx->prev_pos.y)) / mlx->size * fabs(mlx->fractal.end.y - mlx->fractal.start.y);
		mlx->fractal.start.y += co.y;
		mlx->fractal.end.y += co.y;
		fractal_render(mlx);
		mlx->prev_pos = init_complex(x, y);
	}
	return (1);
}

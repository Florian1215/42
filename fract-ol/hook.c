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

static int	hook_loop(t_mlx *mlx)
{
	if (mlx->launch)
	{
		edit_c(mlx, mlx->fractal.c.y < -0.4 ? 0.07 : 0.03, &mlx->fractal.c.y);
		if (mlx->fractal.c.y > 0)
		{
			edit_c(mlx, -mlx->fractal.c.y, &mlx->fractal.c.y);
			mlx->launch = 0;
		}
	}
	else if (mlx->in_menu)
	{
		if (mlx->hover.value >= 0.87 || mlx->prev_hover.value < 1)
		{
			if (mlx->hover.value >= 0.87)
				mlx->hover.value -= 0.03;
			else if (mlx->hover.value >= 0.95)
				mlx->hover.value -= 0.01;
			if (mlx->prev_hover.value < 0.87)
				mlx->prev_hover.value += 0.02;
			else if (mlx->prev_hover.value < 1)
				mlx->prev_hover.value += 0.04;
			set_menu(mlx);
		}
	}
	return (1);
}

void	set_hook(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, key_event_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_event_press, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_event_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_event_motion, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_mlx, mlx);
	mlx_key_hook(mlx->win_ptr, key_event, mlx);
	mlx_loop_hook(mlx->mlx_ptr, hook_loop, mlx);
}

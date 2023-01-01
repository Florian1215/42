/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:30:44 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/14 15:30:45 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop(t_mlx *mlx)
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
		if (mlx->hover.value >= 0.80 || mlx->prev_hover.value < 1)
		{
			if (mlx->hover.value >= 0.80)
				mlx->hover.value -= 0.03;
			else if (mlx->hover.value >= 0.95)
				mlx->hover.value -= 0.01;
			if (mlx->prev_hover.value < 0.85)
				mlx->prev_hover.value += 0.06;
			else if (mlx->prev_hover.value < 0.95)
				mlx->prev_hover.value += 0.04;
			else if (mlx->prev_hover.value < 1)
				mlx->prev_hover.value += 0.02;
			set_menu(mlx);
		}
	}
	return (1);
}

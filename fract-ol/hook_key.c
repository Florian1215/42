/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:08:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/05 15:25:28 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_event_preset(t_mlx *mlx, int k)
{
	if (k == NUM_0)
		set_preset(mlx, PRESET_0);
	else if (k == NUM_1)
		set_preset(mlx, PRESET_1);
	else if (k == NUM_2)
		set_preset(mlx, PRESET_2);
	else if (k == NUM_3)
		set_preset(mlx, PRESET_3);
	else if (k == NUM_4)
		set_preset(mlx, PRESET_4);
	else if (k == NUM_5)
		set_preset(mlx, PRESET_5);
	else if (k == NUM_6)
		set_preset(mlx, PRESET_6);
	else if (k == NUM_7)
		set_preset(mlx, PRESET_7);
	else if (k == NUM_8)
		set_preset(mlx, PRESET_8);
	else if (k == NUM_9)
		set_preset(mlx, PRESET_9);
}

int	key_event(int k, t_mlx *mlx)
{
	if (mlx->slide.slide)
		return (0);
	if (k == ESQ)
		close_mlx(mlx);
	if (mlx->in_menu)
		return (0);
	else if (k == Q)
	{
		mlx->launch = 1;
		set_fractal(mlx, mlx->fractal.set);
		set_color(mlx, mlx->fractal.color);
		fractal_render(mlx);
	}
	else if (k == TAB)
		set_menu(mlx);
	else if (k == W)
	{
		mlx->launch = 1;
		set_fractal(mlx, ++mlx->fractal.set % 12);
		set_color(mlx, mlx->fractal.color);
	}
	else
		key_event_preset(mlx, k);
	return (1);
}

static void	key_event_fractal(t_mlx *mlx, int k)
{
	if (k == LEFT)
		edit_c(mlx, 0.01, &mlx->fractal.c.y);
	else if (k == DOWN)
		edit_c(mlx, 0.01, &mlx->fractal.c.x);
	else if (k == RIGHT)
		edit_c(mlx, -0.01, &mlx->fractal.c.y);
	else if (k == UP)
		edit_c(mlx, -0.01, &mlx->fractal.c.x);
	else if (k == PLUS)
		edit_iter(mlx, 10);
	else if (k == MINUS)
		edit_iter(mlx, -10);
}

int	key_event_press(int k, t_mlx *mlx)
{
	if (mlx->slide.slide)
		return (0);
	if (k == D)
		toggle_appearance(mlx);
	else if (k == C)
		edit_color(mlx);
	else if (mlx->in_menu && (k == LEFT || k == RIGHT))
		slide_page(mlx, k);
	else if (!mlx->in_menu)
		key_event_fractal(mlx, k);
	return (1);
}

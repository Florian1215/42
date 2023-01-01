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

int	mouse_event_press(int button, int x, int y, t_mlx *mlx)
{
	t_co		co;

	if (mlx->in_menu)
	{
		if (button == LEFT_CLICK)
		{
			mlx->in_menu = 0;
			mlx->launch = 1;
			set_fractal(mlx, mlx->menu[select_fractal(mlx, init_complex(x, y))]);
			set_color(mlx, mlx->fractal.color);
		}
	}
	else
	{
		if (button == SCROLL_IN || button == SCROLL_OUT)
		{
			co.x = (double)x / (mlx->size / (mlx->fractal.end.x - \
				mlx->fractal.start.x)) + mlx->fractal.start.x;
			co.y = (double)y / (mlx->size / (mlx->fractal.end.y - \
				mlx->fractal.start.y)) * -1 + mlx->fractal.end.y;
			zoom(mlx, (button == SCROLL_IN) ? 1 / 1.3 : 1.3, co);
		}
		else if (button == LEFT_CLICK)
		{
			mlx->prev_pos = init_complex(x, y);
			mlx->moving = 1;
		}
	}
	return (1);
}

int	mouse_event_release(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (!mlx->in_menu && button == LEFT_CLICK)
		mlx->moving = 0;
	return (1);
}

int	key_event(int k, t_mlx *mlx)
{
	if (k == ESQ)
		close_mlx(mlx);
	if (mlx->in_menu)
		return (0);
	if (k == Q)
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
		set_fractal(mlx, ++mlx->fractal.set % 6);
		set_color(mlx, mlx->fractal.color);
	}
	else if (k == NUM_0)
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
	return (1);
}

static int	key_event_press(int k, t_mlx *mlx)
{
	if (k == D)
		toggle_appearance(mlx);
	else if (k == C)
		edit_color(mlx);
	if (mlx->in_menu)
	{
		if (k == LEFT || k == RIGHT)
			set_page(mlx, ++mlx->page % 2);
	}
	else
	{
		if (k == LEFT)
			edit_c(mlx, 0.03, &mlx->fractal.c.y);
		else if (k == DOWN)
			edit_c(mlx, 0.03, &mlx->fractal.c.x);
		else if (k == RIGHT)
			edit_c(mlx, -0.03, &mlx->fractal.c.y);
		else if (k == UP)
			edit_c(mlx, -0.03, &mlx->fractal.c.x);
		else if (k == PLUS)
			edit_iter(mlx, 10);
		else if (k == MINUS)
			edit_iter(mlx, -10);
	}
	return (1);
}

void	set_hook(t_mlx *mlx)
{
	mlx_key_hook(mlx->win_ptr, key_event, mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_event_press, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_mlx, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_event_press, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_event_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_event_motion, mlx);
	mlx_loop_hook(mlx->mlx_ptr, loop, mlx);
}

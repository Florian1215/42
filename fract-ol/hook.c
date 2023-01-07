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
	if (mlx->c_animate)
		c_animation(mlx);
	else if (mlx->reset)
		reset_animation(mlx);
	else if (mlx->in_menu && mlx->slide.start)
		render_slide(mlx);
	else if (mlx->in_menu && (mlx->hover.pos != POS_ERROR || mlx->prev_hover.pos != POS_ERROR))
		hover_animation(mlx);
	return (1);
}

static int	key_event(int k, t_mlx *mlx)
{
	if (mlx->slide.slide || mlx->reset)
		return (0);
	if (k == ESQ)
		close_mlx(mlx);
	if (mlx->in_menu)
		return (0);
	else if (k == Q && !mlx->c_animate)
		mlx->reset = TRUE;
	else if (k == TAB)
		set_menu(mlx);
	else if (k == W)
		launch_fractal(mlx, mlx->fractal.set ? --mlx->fractal.set : 11);
	else if (k == E)
		launch_fractal(mlx, ++mlx->fractal.set % 12);
	else if (k >= NUM_0 && k <= NUM_9 && k != 90 && !mlx->c_animate)
		set_preset(mlx, k - 82 - (k >= NUM_8));
	return (1);
}

static void	key_event_fractal(t_mlx *mlx, int k)
{
	if (k == LEFT)
		edit_c(mlx, 0.1, &mlx->fractal.c.y);
	else if (k == DOWN)
		edit_c(mlx, 0.1, &mlx->fractal.c.x);
	else if (k == RIGHT)
		edit_c(mlx, -0.1, &mlx->fractal.c.y);
	else if (k == UP)
		edit_c(mlx, -0.1, &mlx->fractal.c.x);
	else if (k == PLUS)
		edit_iter(mlx, 10);
	else if (k == MINUS)
		edit_iter(mlx, -10);
}

static int	key_event_press(int k, t_mlx *mlx)
{
	if (mlx->slide.slide || mlx->reset)
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

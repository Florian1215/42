/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 18:02:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mouse_event_fractal(t_mlx *mlx, int button, int x, int y)
{
	t_co		co;

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
		mlx->moving = TRUE;
	}
	else if (button == RIGHT_CLICK)
	{
		mlx->edit_c = TRUE;
		mouse_event_motion(x, y, mlx);
	}
}

int	mouse_event_press(int button, int x, int y, t_mlx *mlx)
{
	if (mlx->slide.slide || mlx->reset || mlx->c_animate)
		return (0);
	if (mlx->in_menu)
		launch_fractal(mlx, mlx->menu[select_fractal(mlx, init_complex(x, y))]);
	else
		mouse_event_fractal(mlx, button, x, y);
	return (1);
}

int	mouse_event_release(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (!mlx->in_menu)
	{
		if (button == LEFT_CLICK)
			mlx->moving = FALSE;
		else if (button == RIGHT_CLICK)
			mlx->edit_c = FALSE;
	}
	return (1);
}

int	mouse_event_motion(int x, int y, t_mlx *mlx)
{
	t_pos	current;

	if (mlx->slide.slide || mlx->reset || mlx->c_animate)
		return (0);
	if (mlx->in_menu)
	{
		current = select_fractal(mlx, init_complex(x, y));
		if (current != mlx->hover.pos)
		{
			mlx->hover.i = 0;
			mlx->prev_hover = mlx->hover;
			mlx->hover.pos = current;
			mlx->hover.value = 1;
			set_menu(mlx);
		}
	}
	else if (mlx->moving)
		move(mlx, x, y);
	else if (mlx->edit_c)
	{
		mlx->fractal.c = init_complex((double)(x - (mlx->size / 2)) / (mlx->size / 4), (double)(y - (mlx->size / 2)) / (mlx->size / 4));
		fractal_render(mlx);
	}
	return (1);
}

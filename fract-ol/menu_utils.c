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

t_pos	select_fractal(t_mlx *mlx, t_co co)
{
	int	hsize;

	if (co.x > mlx->size || co.y > mlx->size || co.x < 0 || co.y < 0)
		return (POS_ERROR);
	hsize = mlx->size / 2;
	if (co.x < hsize && co.y < hsize)
		return (POS_1);
	else if (co.x > hsize && co.y < hsize)
		return (POS_2);
	else if (co.x < hsize && co.y > hsize)
		return (POS_3);
	else
		return (POS_4);
}

int	mouse_event_motion(int x, int y, t_mlx *mlx)
{
	t_pos	current;
	t_co	co;

	if (mlx->in_menu)
	{
		current = select_fractal(mlx, init_complex(x, y));
		if (current != mlx->hover.pos)
		{
			mlx->prev_hover = mlx->hover;
			mlx->hover.pos = current;
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

void	set_page(t_mlx *mlx, int page)
{
	static t_fractals	menu[2][4] = {{MANDELBROT, JULIA, CELTIC, BURNING_SHIP}, {BUFFALO, BURNING_JULIA, MANDELBROT, MANDELBROT}};

	mlx->menu[POS_1] = menu[page][POS_1];
	mlx->menu[POS_2] = menu[page][POS_2];
	mlx->menu[POS_3] = menu[page][POS_3];
	mlx->menu[POS_4] = menu[page][POS_4];
	mlx->page = page;
	set_menu(mlx);
}

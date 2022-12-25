/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:22:30 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:31 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_co	get_coor(t_fractal frac, t_co i, t_mlx *mlx)
{
	t_co	co;
	t_co	size;
	double	hover;

	size = init_coor(frac.end.x - frac.start.x, frac.end.y - frac.start.y);
	hover = 1;
	if (frac.set == mlx->hover.set)
		hover = mlx->hover.value;
	else if (frac.set == mlx->prev_hover.set)
		hover = mlx->prev_hover.value;
	if (frac.set == MANDELBROT)
	{
		co.x = ((i.x - (size.x / 2) - (45 * mlx->size.x / 700)) / (size.x / 2)) * (1.5 * hover);
		co.y = ((i.y - (size.y / 2)) / (size.y / 2)) * (1.5 * hover);
	}
	else if (frac.set == JULIA)
	{
		co.x = (i.x - (size.x * 2) + (170 * mlx->size.x / 700)) / (size.x / 2) * (1.5 * hover);
		co.y = ((i.y - (size.y / 2)) / (frac.end.y / 2)) * (1.5 * hover);
	}
	else if (frac.set == CELTIC)
	{
		co.x = (i.x - (size.x / 2)) / (size.x / 2) * (1.8 * hover);
		co.y = (i.y - (size.y * 2) + (120 * mlx->size.x / 700)) / (size.y / 2) * (1.8 * hover);
	}
	else
	{
		co.x = (i.x - (size.x * 2) + (130 * mlx->size.x / 700)) / (size.x / 2) * (1.6 * hover);
		co.y = ((i.y - (size.y / 2) - (380 * mlx->size.x / 700)) / (size.y / 2)) * (1.6 * hover);
	}
	return (co);
}

static void	fractal_preview(t_preview_thread *t)
{
	t_co	i;
	double	col;

	set_color(t->mlx, t->frac.color);
	i.x = t->frac.start.x - 1;
	while (++i.x < t->frac.end.x)
	{
		i.y = t->frac.start.y - 1;
		while (++i.y < t->frac.end.y)
		{
			col = t->frac.func(t->mlx, get_coor(t->frac, i, t->mlx), t->frac.color);
			mlx_put_pixel_img(&t->mlx->img, i, col);
		}
	}
}

static int	get_pos_txt(t_mlx *mlx, int pos, int diff)
{
	return ((int)(mlx->size.x / 4) * pos - diff);
}

void	set_menu(t_mlx *mlx)
{
	int					i;
	t_preview_thread	t[4];

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->in_menu = 1;
	mlx->launch = 0;
	i = -1;
	while (++i < 4)
	{
		set_fractal(mlx, i);
		set_color(mlx, mlx->fractal.color);
		mlx->fractal.color = mlx->color;
		t[i].mlx = mlx;
		t[i].frac = mlx->fractal;
		pthread_create(&t[i].thread, NULL, (void *)fractal_preview, &t[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(t[i].thread, NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, 1, 20), get_pos_txt(mlx, 1, -3), WHITE, "Mandelbrot");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, 3, 15), get_pos_txt(mlx, 1, -3), WHITE, "Julia");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, 1, 18), get_pos_txt(mlx, 3, -3), WHITE, "Celtic");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, 3, 36), get_pos_txt(mlx, 3, -3), WHITE, "Burning Ship");
}

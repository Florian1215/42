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

static t_co	get_coor(t_mlx *mlx, t_fractal frac, t_co i)
{
	double	hover;

	hover = 1;
	if (mlx->hover.pos != POS_ERROR && frac.set == mlx->menu[mlx->hover.pos])
		hover = mlx->hover.value;
	else if (mlx->prev_hover.pos != POS_ERROR && frac.set == mlx->menu[mlx->prev_hover.pos])
		hover = mlx->prev_hover.value;
	return (frac.coor(i, mlx->size / 2, hover));
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
			col = t->frac.sequence(t->mlx, t->frac, get_coor(t->mlx, t->frac, i));
			mlx_put_pixel_img(&t->mlx->img, i, col);
		}
	}
}

static int	get_pos_txt(t_mlx *mlx, int pos, int diff)
{
	return ((int)(mlx->size / 4) * pos - diff);
}

static void	get_pos_menu(t_mlx *mlx, int i, int hsize)
{
	if (i == 0)
		mlx->fractal.start = init_complex(0, 0);
	else if (i == 1)
		mlx->fractal.start = init_complex(hsize, 0);
	else if (i == 2)
		mlx->fractal.start = init_complex(0, hsize);
	else
		mlx->fractal.start = init_complex(hsize, hsize);
	mlx->fractal.end = init_complex(mlx->fractal.start.x + hsize, mlx->fractal.start.y + hsize);
}

void	set_menu(t_mlx *mlx)
{
	int					i;
	t_preview_thread	t[4];

	mlx->in_menu = 1;
	mlx->launch = 0;
	i = -1;
	while (++i < 4)
	{
		set_fractal(mlx, mlx->menu[i]);
		get_pos_menu(mlx, i, mlx->size / 2);
		set_color(mlx, mlx->fractal.color);
		mlx->fractal.color = mlx->color;
		if ((int)mlx->hover.pos == i)
			mlx->fractal.max_iter -= (1 - mlx->hover.value) * 90;
		else if ((int)mlx->prev_hover.pos == i)
			mlx->fractal.max_iter -= (1 - mlx->prev_hover.value) * 90;
		t[i].mlx = mlx;
		t[i].frac = mlx->fractal;
		pthread_create(&t[i].thread, NULL, (void *)fractal_preview, &t[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(t[i].thread, NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	i = -1;
	while (++i < 4)
	{
		set_fractal(mlx, mlx->menu[i]);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, i % 2 ? 3 : 1, mlx->fractal.diff), get_pos_txt(mlx, i < 2 ? 1 : 3, -3), FG, mlx->fractal.name);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, i % 2 ? 3 : 1, mlx->fractal.diff - 1), get_pos_txt(mlx, i < 2 ? 1 : 3, -4), FG, mlx->fractal.name);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, i % 2 ? 3 : 1, mlx->fractal.diff - 2), get_pos_txt(mlx, i < 2 ? 1 : 3, -5), FG, mlx->fractal.name);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, i % 2 ? 3 : 1, mlx->fractal.diff), get_pos_txt(mlx, i < 2 ? 1 : 3, -3), WHITE, mlx->fractal.name);
	}
}

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

static t_co	get_coor(t_mlx *mlx, t_fractal frac, t_co i)
{
	double	hover;
	t_co	co;

	hover = 1;
	if (mlx->hover.pos != POS_ERROR && frac.set == mlx->menu[mlx->hover.pos])
		hover = mlx->hover.value;
	else if (mlx->prev_hover.pos != POS_ERROR && frac.set == mlx->menu[mlx->prev_hover.pos])
		hover = mlx->prev_hover.value;
	co.x = ((i.x - frac.start.x) - (mlx->size / 2) / 4 + (frac.offset_coor.x * mlx->size / 1000)) / ((mlx->size / 2) / 2) * (frac.size_zoom * hover);
	co.y = ((i.y - frac.start.y) - (mlx->size / 2) / 4 + (frac.offset_coor.y * mlx->size / 1000)) / ((mlx->size / 2) / 2) * (frac.size_zoom * hover);
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
			col = t->frac.sequence(t->mlx, t->frac, get_coor(t->mlx, t->frac, i));
			if (t->mlx->slide.save)
				mlx_put_pixel_img(&t->mlx->slide.img, i, col);
			else
				mlx_put_pixel_img(&t->mlx->img, i, col);
		}
	}
}

void	set_menu(t_mlx *mlx)
{
	int					i;
	t_preview_thread	t[4];

	mlx->in_menu = TRUE;
	mlx->c_animate = FALSE;
	i = -1;
	while (++i < 4)
	{
		set_fractal(mlx, mlx->menu[i]);
		get_pos_menu(mlx, i, mlx->size / 2);
		set_color(mlx, mlx->fractal.color);
		mlx->fractal.color = mlx->color;
		if ((int)mlx->hover.pos == i)
			mlx->fractal.max_iter -= (1 - mlx->hover.value) * 120;
		else if ((int)mlx->prev_hover.pos == i)
			mlx->fractal.max_iter -= (1 - mlx->prev_hover.value) * 120;
		t[i].mlx = mlx;
		t[i].frac = mlx->fractal;
		pthread_create(&t[i].thread, NULL, (void *)fractal_preview, &t[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(t[i].thread, NULL);
	if (!mlx->slide.slide)
		set_name_fractals(mlx, mlx->img.img, 0);
}

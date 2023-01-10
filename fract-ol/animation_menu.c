/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:54:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/07 16:54:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hover_animation(t_mlx *mlx)
{
	static double	values[9] = {0, 0.01, 0.04, 0.08, 0.10, 0.115, 0.119, 0.127, 0.13};

	if (mlx->hover.pos != POS_ERROR && mlx->hover.i < 9)
		mlx->hover.value = 1 - values[mlx->hover.i++];
	if (mlx->prev_hover.pos != POS_ERROR && mlx->prev_hover.i < 9)
		mlx->prev_hover.value = 1 - values[8] + values[mlx->prev_hover.i++];
	set_menu(mlx);
}

void	render_slide(t_mlx *mlx)
{
	static int	values[30] = {4, 17, 46, 98, 190, 320, 447, 547, 624, 686, 736, 777, 812, 842, 868, 890, 909, 925, 939, 952, 962, 971, 978, 985, 990, 994, 996, 998, 999, 1000};
	static int	i = 0;
	int			tmp;
	int			prev;
	int			x_offset;

	if (i == 30)
	{
		i = 0;
		mlx->slide.start = FALSE;
		mlx->slide.slide = FALSE;
		return ;
	}
	tmp = values[i] * mlx->size / 1000;
	x_offset = mlx->slide.side == RIGHT ? mlx->size - tmp : tmp - mlx->size;
	if (mlx->in_menu)
		set_name_fractals(mlx, mlx->img.img, x_offset);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, x_offset, 0);
	prev = mlx->slide.side == LEFT ? 1 : -1;
	x_offset = mlx->slide.side == RIGHT ? 0 - tmp : tmp;
	if (mlx->in_menu)
	{
		set_page(mlx, mlx->page + prev);
		set_name_fractals(mlx, mlx->slide.img.img, x_offset);
		set_page(mlx, mlx->page - prev);
	}
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->slide.img.img, x_offset, 0);
	i++;
}

void	slide_page(t_mlx *mlx, t_keycode side)
{
	mlx->slide.slide = TRUE;
	mlx->slide.save = TRUE;
	if (mlx->in_menu)
		set_menu(mlx);
	else
		fractal_render(mlx);
	mlx->slide.save = FALSE;
	mlx->slide.side = side;
	if (mlx->in_menu)
	{
		if (side == LEFT)
			set_page(mlx, mlx->page - 1);
		else
			set_page(mlx, mlx->page +1);
		set_menu(mlx);
	}
	else
	{
		if (side == LEFT)
			set_fractal(mlx, mlx->fractal.set ? --mlx->fractal.set : CELTIC_MANDELBROT);
		else
			set_fractal(mlx, ++mlx->fractal.set % 12);
		set_color(mlx, mlx->fractal.color);
		set_preset(mlx, PRESET_0);
		fractal_render(mlx);
	}
	mlx->slide.start = TRUE;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:33:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/06 10:33:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hover_animation(t_mlx *mlx)
{
	static double	pos[9] = {0, 0.01, 0.04, 0.08, 0.10, 0.115, 0.119, 0.127, 0.13};

	if (mlx->hover.pos != POS_ERROR && mlx->hover.i < 9)
		mlx->hover.value = 1 - pos[mlx->hover.i++];
	if (mlx->prev_hover.pos != POS_ERROR && mlx->prev_hover.i < 9)
		mlx->prev_hover.value = 1 - pos[8] + pos[mlx->prev_hover.i++];
	set_menu(mlx);
}

void	render_slide(t_mlx *mlx)
{
	static int	values[21] = {0, 9, 43, 131, 307, 492, 620, 710, 775, 827, 867, 899, 924, 946, 962, 975, 985, 992, 996, 999, 1000};
	static int	i = 0;
	int			x_img;
	int			x_slide;
	int			tmp;

	if (i == 21)
	{
		i = 0;
		mlx->slide.start = 0;
		mlx->slide.slide = 0;
		return ;
	}
	tmp = values[i] * mlx->size / values[20];
	x_img = mlx->slide.side == RIGHT ? mlx->size - tmp : tmp - mlx->size;
	x_slide = mlx->slide.side == RIGHT ? 0 - tmp : tmp;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, x_img, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->slide.img.img, x_slide, 0);
	set_name_fractals(mlx, x_img);
	i++;
}

void	slide_page(t_mlx *mlx, t_keycode side)
{
	mlx->slide.slide = 1;
	mlx->slide.save = 1;
	set_menu(mlx);
	mlx->slide.save = 0;
	mlx->slide.side = side;
	if (side == LEFT)
		set_page(mlx, mlx->page - 1);
	else
		set_page(mlx, mlx->page + 1);
	set_menu(mlx);
	mlx->slide.start = 1;
}

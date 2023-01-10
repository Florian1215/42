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

static int	get_pos_txt(t_mlx *mlx, int pos, int offset)
{
	return ((int)(mlx->size / 4) * pos - offset);
}

void	set_name_fractals(t_mlx *mlx, void *img, int x_offset)
{
	int	i;

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img, x_offset, 0);
	i = -1;
	while (++i < 4)
	{
		set_fractal(mlx, mlx->menu[i]);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, i % 2 ? 3 : 1, mlx->fractal.offset_name) + x_offset, get_pos_txt(mlx, i < 2 ? 1 : 3, -3), FG, mlx->fractal.name);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, i % 2 ? 3 : 1, mlx->fractal.offset_name - 1) + x_offset, get_pos_txt(mlx, i < 2 ? 1 : 3, -4), FG, mlx->fractal.name);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, i % 2 ? 3 : 1, mlx->fractal.offset_name - 2) + x_offset, get_pos_txt(mlx, i < 2 ? 1 : 3, -5), FG, mlx->fractal.name);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos_txt(mlx, i % 2 ? 3 : 1, mlx->fractal.offset_name) + x_offset, get_pos_txt(mlx, i < 2 ? 1 : 3, -3), WHITE, mlx->fractal.name);
	}
}

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

void	set_page(t_mlx *mlx, int page)
{
	static t_fractals	menu[3][4] = {\
				{MANDELBROT, JULIA, CELTIC, BURNING_SHIP}, \
				{BUFFALO, BURNING_JULIA, JULIA3, CELTIC_MANDELBAR}, \
				{PERPENDICULAR_CELTIC, HEART, MANDELBAR, CELTIC_MANDELBROT}};

	if (page > 2)
		page = 0;
	else if (page < 0)
		page = 2;
	mlx->menu[POS_1] = menu[page][POS_1];
	mlx->menu[POS_2] = menu[page][POS_2];
	mlx->menu[POS_3] = menu[page][POS_3];
	mlx->menu[POS_4] = menu[page][POS_4];
	mlx->page = page;
	if (!mlx->slide.slide)
		set_menu(mlx);
}

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

void	set_page(t_mlx *mlx, int page)
{
	static t_fractals	menu[3][4] = {\
				{MANDELBROT, JULIA, CELTIC, BURNING_SHIP}, \
				{BUFFALO, BURNING_JULIA, JULIA3, CELTIC_MANDELBAR}, \
				{PERPENDICULAR_CELTIC, HEART, MANDELBAR, CELTIC_MANDELBROT}};

	if (page < 0)
		page = 2;
	mlx->menu[POS_1] = menu[page][POS_1];
	mlx->menu[POS_2] = menu[page][POS_2];
	mlx->menu[POS_3] = menu[page][POS_3];
	mlx->menu[POS_4] = menu[page][POS_4];
	mlx->page = page;
	set_menu(mlx);
}

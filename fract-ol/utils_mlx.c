/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:49:35 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/10 10:49:36 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_co	init_complex(double x, double y)
{
	t_co	co;

	co.x = x;
	co.y = y;
	return (co);
}

void	init_hover(t_mlx *mlx)
{
	mlx->hover.pos = POS_ERROR;
	mlx->hover.value = 1;
	mlx->prev_hover.pos = POS_ERROR;
	mlx->prev_hover.value = 1;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->size = 1000;
	mlx->in_menu = 1;
	mlx->launch = 0;
	mlx->offset_color = 0;
	mlx->appearance = LIGHT;
	mlx->moving = 0;
	mlx->render = 0;
	mlx->slide.slide = 0;
	mlx->slide.start = 0;
	mlx->slide.save = 0;
	mlx->edit_c = 0;
	init_hover(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (int)mlx->size, (int)mlx->size, "Fract-ol");
	mlx->slide.img.img = mlx_new_image(mlx, (int)mlx->size, (int)mlx->size);
	mlx->slide.img.addr = mlx_get_data_addr(mlx->slide.img.img, &mlx->slide.img.bits_per_pixel, &mlx->slide.img.line_length, &mlx->slide.img.endian);
	mlx->img.img = mlx_new_image(mlx, (int)mlx->size, (int)mlx->size);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
}

void	mlx_put_pixel_img(t_img *img, t_co co, int color)
{
	*(unsigned int *)(img->addr + ((int)co.y * img->line_length + (int)co.x * (img->bits_per_pixel / 8))) = color;
}

int	close_mlx(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->img.addr);
	free(mlx->slide.img.addr);
	exit(0);
}

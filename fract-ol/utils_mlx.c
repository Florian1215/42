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

void	init_zoom(t_mlx *mlx)
{
	mlx->zoom.start = init_coor(-2, -2);
	mlx->zoom.end.x = 2;
	mlx->zoom.end.y = mlx->zoom.start.y + (mlx->zoom.end.x - mlx->zoom.start.x) * mlx->size.y / mlx->size.x;
	mlx->zoom.scale = 1.1;
	mlx->max_iter = 30;
}

void	init_mlx(t_mlx **mlx)
{
	*mlx = malloc(sizeof(t_mlx));
	if (!*mlx)
		return ;
	(*mlx)->mlx_ptr = mlx_init();
	(*mlx)->size = init_coor(700, 700);
	init_zoom(*mlx);
	(*mlx)->color_set = GREEN;
	(*mlx)->in_menu = 1;
	set_color(*mlx, 0);
	(*mlx)->win_ptr = mlx_new_window((*mlx)->mlx_ptr, (*mlx)->size.x, (*mlx)->size.y, "Fract-ol");
	(*mlx)->img.img = mlx_new_image(mlx, (*mlx)->size.x, (*mlx)->size.y);
	(*mlx)->img.addr = mlx_get_data_addr((*mlx)->img.img, &(*mlx)->img.bits_per_pixel, &(*mlx)->img.line_length, &(*mlx)->img.endian);
}

void	mlx_put_pixel_img(struct s_img *img, t_co co, int color)
{
	*(unsigned int*)(img->addr + ((int)co.y * img->line_length + (int)co.x * (img->bits_per_pixel / 8))) = color;
}

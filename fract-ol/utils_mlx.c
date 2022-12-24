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

t_co	init_coor(double x, double y)
{
	t_co	co;

	co.x = x;
	co.y = y;
	return (co);
}

void	init_hover(t_mlx *mlx)
{
	mlx->hover.set = -1;
	mlx->hover.value = 1;
	mlx->prev_hover = mlx->hover;
}

void	init_mlx(t_mlx **mlx)
{
	*mlx = malloc(sizeof(t_mlx));
	if (!*mlx)
		return ;
	(*mlx)->mlx_ptr = mlx_init();
	(*mlx)->size = init_coor(1000, 1000);
	(*mlx)->in_menu = 1;
	(*mlx)->launch = 0;
	(*mlx)->offset_color = 0;
	(*mlx)->appearance = LIGHT;
	(*mlx)->moving = 0;
	init_hover(*mlx);
	(*mlx)->win_ptr = mlx_new_window((*mlx)->mlx_ptr, (int)(*mlx)->size.x, \
		(int)(*mlx)->size.y, "Fract-ol");
	(*mlx)->img.img = mlx_new_image(mlx, (int)(*mlx)->size.x, \
		(int)(*mlx)->size.y);
	(*mlx)->img.addr = mlx_get_data_addr((*mlx)->img.img, &(*mlx)-> \
		img.bits_per_pixel, &(*mlx)->img.line_length, &(*mlx)->img.endian);
}

void	mlx_put_pixel_img(struct s_img *img, t_co co, int color)
{
	*(unsigned int *)(img->addr + ((int)co.y * img->line_length + (int)co.x * \
		(img->bits_per_pixel / 8))) = color;
}

int	close_mlx(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->img.addr);
	free(mlx);
	exit(0);
}

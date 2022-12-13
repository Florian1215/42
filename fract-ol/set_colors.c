/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:22:37 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:39 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_1(t_mlx *mlx)
{
	mlx->color = init_color(0xB9E0A2, 0xA4bE7B, 0x3D663D, GREEN);
}

void	set_2(t_mlx *mlx)
{
	mlx->color = init_color(0xD7572B, 0xDA7B27, 0xFFCA5A, YELLOW);
}

void	set_3(t_mlx *mlx)
{
	mlx->color = init_color(0xA7DDBC, 0x8FC5AA, 0x316764, BLUE);
}

void	set_4(t_mlx *mlx)
{
	mlx->color = init_color(0xC24844, 0xEB5752, 0xFFD0CC, RED);
}

void	set_5(t_mlx *mlx)
{
	mlx->color = init_color(0xEEEFE3, 0xBBC7A5, 0x363432, GREY);
}

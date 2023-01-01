/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_set2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:21:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/01 14:21:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_burning_shipe(t_mlx *mlx)
{
	mlx->fractal.set = BURNING_SHIP;
	mlx->fractal.start = init_complex(-2.4, 1.6);
	mlx->fractal.end = init_complex(1.6, -2.4);
	mlx->fractal.sequence = burning_shipe;
	mlx->fractal.coor = coor_burning_ship;
	mlx->fractal.color = RED;
	mlx->fractal.name = "Burning Ship";
	mlx->fractal.diff = 36;
}

void	set_buffalo(t_mlx *mlx)
{
	mlx->fractal.set = BUFFALO;
	mlx->fractal.start = init_complex(-2, -2);
	mlx->fractal.end = init_complex(2, 2);
	mlx->fractal.sequence = buffalo;
	mlx->fractal.coor = coor_buffalo;
	mlx->fractal.color = BLUE_RED;
	mlx->fractal.name = "Buffalo";
	mlx->fractal.diff = 25;
	mlx->fractal.c = init_complex(0.36, -0.69);
}

void	set_burning_julia(t_mlx *mlx)
{
	mlx->fractal.set = BURNING_JULIA;
	mlx->fractal.start = init_complex(-2, -2);
	mlx->fractal.end = init_complex(2, 2);
	mlx->fractal.sequence = burning_julia;
	mlx->fractal.coor = coor_burning_julia;
	mlx->fractal.color = PINK;
	mlx->fractal.name = "Burning Julia";
	mlx->fractal.diff = 45;
	mlx->fractal.c = init_complex(0.92, -0.54);
}

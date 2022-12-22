/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:22:52 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:53 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_mandelbrot(t_mlx *mlx)
{
	t_co	start;
	t_co	end;

	if (mlx->in_menu)
	{
		start = init_coor(0, 0);
		end = init_coor(mlx->size.x / 2, mlx->size.y / 2);
	}
	else
	{
		start = init_coor(-2.2, -2);
		end = init_coor(1.8, 2);
	}
	mlx->fractal = init_fractal(MANDELBROT, start, end, &mandelbrot, GREEN);
}

static void	set_julia(t_mlx *mlx)
{
	t_co	start;
	t_co	end;

	mlx->c = init_coor(1, 0 - (mlx->launch * 2));
	if (mlx->in_menu)
	{
		start = init_coor(mlx->size.x / 2, 0);
		end = init_coor(mlx->size.x, mlx->size.y / 2);
	}
	else
	{
		start = init_coor(-2, -2);
		end = init_coor(2, 2);
	}
	mlx->fractal = init_fractal(JULIA, start, end, &julia, PURPLE);
}

static void	set_celtic(t_mlx *mlx)
{
	t_co	start;
	t_co	end;

	if (mlx->in_menu)
	{
		start = init_coor(0, mlx->size.y / 2);
		end = init_coor(mlx->size.x / 2, mlx->size.y);
	}
	else
	{
		start = init_coor(-2, 1.3);
		end = init_coor(2, -2.7);
	}
	mlx->fractal = init_fractal(CELTIC, start, end, &celtic, BLUE);
}

static void	set_burning_shipe(t_mlx *mlx)
{
	t_co	start;
	t_co	end;

	if (mlx->in_menu)
	{
		start = init_coor(mlx->size.x / 2, mlx->size.y / 2);
		end = init_coor(mlx->size.x, mlx->size.y);
	}
	else
	{
		start = init_coor(-2.4, 1.6);
		end = init_coor(1.6, -2.4);
	}
	mlx->fractal = init_fractal(BURNING_SHIP, start, end, &burning_shipe, RED);
}

void	set_fractal(t_mlx *mlx, t_fractals set)
{
	static void	(*fractals_set[5])(t_mlx *) = {set_mandelbrot, set_julia, set_celtic, set_burning_shipe};

	if (!mlx->in_menu)
		init_hover(mlx);
	mlx->c = init_coor(0, 0 - (mlx->launch * 2));
	mlx->max_iter = 50;
	fractals_set[set](mlx);
}

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
		start = init_complex(0, 0);
		end = init_complex(mlx->size / 2, mlx->size / 2);
	}
	else
	{
		start = init_complex(-2.2, -2);
		end = init_complex(1.8, 2);
	}
	mlx->fractal.set = MANDELBROT;
	mlx->fractal.start = start;
	mlx->fractal.end = end;
	mlx->fractal.func = mandelbrot;
	mlx->fractal.color = GREEN;
	mlx->fractal.name = "Mandelbrot";
}

static void	set_julia(t_mlx *mlx)
{
	t_co	start;
	t_co	end;

	if (mlx->in_menu)
	{
		start = init_complex(mlx->size / 2, 0);
		end = init_complex(mlx->size / 2 * 2, mlx->size / 2);
	}
	else
	{
		start = init_complex(-2, -2);
		end = init_complex(2, 2);
	}
	mlx->fractal.set = JULIA;
	mlx->fractal.start = start;
	mlx->fractal.end = end;
	mlx->fractal.func = julia;
	mlx->fractal.color = PURPLE;
	mlx->fractal.name = "Julia";
	set_preset(mlx, PRESET_1);
}

static void	set_celtic(t_mlx *mlx)
{
	t_co	start;
	t_co	end;

	if (mlx->in_menu)
	{
		start = init_complex(0, mlx->size / 2);
		end = init_complex(mlx->size / 2, mlx->size);
	}
	else
	{
		start = init_complex(-2, 1.3);
		end = init_complex(2, -2.7);
	}
	mlx->fractal.set = CELTIC;
	mlx->fractal.start = start;
	mlx->fractal.end = end;
	mlx->fractal.func = celtic;
	mlx->fractal.color = BLUE;
	mlx->fractal.name = "Celtic";
}

void	set_fractal(t_mlx *mlx, t_fractals set)
{
	static void	(*fractals_set[6])(t_mlx *) = {set_mandelbrot, set_julia, set_celtic, set_burning_shipe, set_buffalo, set_burning_julia};

	if (!mlx->in_menu)
		init_hover(mlx);
	set_preset(mlx, PRESET_0);
	fractals_set[set](mlx);
	mlx->fractal.max_iter = 50;
}

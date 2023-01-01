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
	t_co	start;
	t_co	end;

	if (mlx->in_menu)
	{
		start = init_complex(mlx->size / 3, mlx->size / 2);
		end = init_complex(mlx->size / 3 * 2, mlx->size);
	}
	else
	{
		start = init_complex(-2.4, 1.6);
		end = init_complex(1.6, -2.4);
	}
	mlx->fractal.set = BURNING_SHIP;
	mlx->fractal.start = start;
	mlx->fractal.end = end;
	mlx->fractal.func = burning_shipe;
	mlx->fractal.color = RED;
	mlx->fractal.name = "Burning Ship";
}

void	set_buffalo(t_mlx *mlx)
{
	t_co	start;
	t_co	end;

	if (mlx->in_menu)
	{
		start = init_complex(mlx->size / 3 * 2, 0);
		end = init_complex(mlx->size, mlx->size / 2);
	}
	else
	{
		start = init_complex(-2.4, 1.6);
		end = init_complex(1.6, -2.4);
	}
	mlx->fractal.set = BUFFALO;
	mlx->fractal.start = start;
	mlx->fractal.end = end;
	mlx->fractal.func = buffalo;
	mlx->fractal.color = BLUE_RED;
	mlx->fractal.name = "Buffalo";
}

void	set_burning_julia(t_mlx *mlx)
{
	t_co	start;
	t_co	end;

	if (mlx->in_menu)
	{
		start = init_complex(mlx->size / 3 * 2, mlx->size / 2);
		end = init_complex(mlx->size, mlx->size);
	}
	else
	{
		start = init_complex(-2.4, 1.6);
		end = init_complex(1.6, -2.4);
	}
	mlx->fractal.set = BURNING_JULIA;
	mlx->fractal.start = start;
	mlx->fractal.end = end;
	mlx->fractal.func = burning_julia;
	mlx->fractal.color = PINK;
	mlx->fractal.name = "Burning Julia";
}

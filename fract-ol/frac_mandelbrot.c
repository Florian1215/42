/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:28:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:28:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_green(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {}, {0xFFB03B}, {0xB64926}, {0x8E2800}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
		{
			pal[0].color = FG;
			pal[1].color = 0x295E52;
		}
		else
		{
			pal[0].color = 0x468966;
			pal[1].color = 0xFFF0A5;
		}
		app = new_app;
	}
	return (pal);
}

void	set_mandelbrot(t_mlx *mlx)
{
	mlx->fractal.set = MANDELBROT;
	mlx->fractal.start = init_complex(-2.2, -2);
	mlx->fractal.end = init_complex(1.8, 2);
	mlx->fractal.sequence = mandelbrot;
	mlx->fractal.coor = init_complex(-200, -122);
	mlx->fractal.color = GREEN;
	mlx->fractal.diff = 20;
	mlx->fractal.name = "Mandelbrot";
}

int	mandelbrot(t_mlx *mlx, t_fractal frac, t_co c)
{
	t_co	z;
	int		i;
	t_co	sqr;

	z = init_complex(frac.c.x, frac.c.y);
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	i = -1;
	while (++i < frac.max_iter)
	{
		z.y = 2 * z.x * z.y + c.y;
		z.x = sqr.x - sqr.y + c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}

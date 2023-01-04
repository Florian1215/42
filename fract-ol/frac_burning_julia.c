/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_burning_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:35:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:35:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_pink(t_appearance new_app)
{
	static t_color		pal[5] = {};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
		{
			pal[0].color = FG;
			pal[1].color = 0x333F58;
			pal[2].color = 0x4A7A96;
			pal[3].color = 0xEE8695;
			pal[4].color = 0xFBBBAD;
		}
		else
		{
			pal[0].color = 0xEE7788;
			pal[1].color = 0xFFCCCC;
			pal[2].color = 0xFF99AA;
			pal[3].color = 0xCC4466;
			pal[4].color = 0x441122;
		}
		app = new_app;
	}
	return (pal);
}

void	set_burning_julia(t_mlx *mlx)
{
	mlx->fractal.set = BURNING_JULIA;
	mlx->fractal.start = init_complex(-2, 2);
	mlx->fractal.end = init_complex(2, -2);
	mlx->fractal.sequence = burning_julia;
	mlx->fractal.coor = init_complex(-125, -125);
	mlx->fractal.color = PINK;
	mlx->fractal.name = "Burning Julia";
	mlx->fractal.diff = 45;
	mlx->fractal.c = init_complex(0.92, -0.54);
}

int	burning_julia(t_mlx *mlx, t_fractal frac, t_co c)
{
	t_co	z;
	t_co	sqr;
	int		i;

	z = init_complex(c.x, c.y);
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	i = -1;
	while (++i < frac.max_iter)
	{
		z.y = fabs(2 * z.x * z.y - frac.c.y);
		z.x = sqr.x - sqr.y - frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}
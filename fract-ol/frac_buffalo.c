/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_buffalo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:33:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:33:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_blue_red(t_appearance new_app)
{
	static t_color		pal[5] = {};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
		{
			pal[0].color = FG;
			pal[1].color = 0x263248;
			pal[2].color = 0x7E8AA2;
			pal[3].color = 0xE3DFBB;
			pal[4].color = 0xF0642A;
		}
		else
		{
			pal[0].color = 0x00748E;
			pal[1].color = 0xE3DFBB;
			pal[2].color = 0xF4BA4D;
			pal[3].color = 0xE3753C;
			pal[4].color = 0xDA3B3A;
		}
		app = new_app;
	}
	return (pal);
}

t_co	preset_buffalo(t_preset preset)
{
	// 0.36, -0.69
	(void)preset;
	return (init_complex(0, 0));
}

void	set_buffalo(t_mlx *mlx)
{
	mlx->fractal.set = BUFFALO;
	mlx->fractal.start = init_complex(-2, 2);
	mlx->fractal.end = init_complex(2, -2);
	mlx->fractal.sequence = buffalo;
	mlx->fractal.offset_coor = init_complex(-125, -122);
	mlx->fractal.color = BLUE_RED;
	mlx->fractal.name = "Buffalo";
	mlx->fractal.offset_name = 25;
	mlx->fractal.c = init_complex(-1.140000, 0.060000);
}

int	buffalo(t_mlx *mlx, t_fractal frac, t_co z)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = 2 * fabs(z.x * z.y) + frac.c.y;
		z.x = fabs(sqr.x - sqr.y) + frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}

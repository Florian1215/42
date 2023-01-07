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

static t_co	preset_buffalo(t_preset preset)
{
	static double	presets[10][2] = {
	{-1.14, 0.06},
	{0.406, -0.936},
	{-0.936, 0.052},
	{0.536, -1.026},
	{-1.752, -0.544},
	{0.366, -0.676},
	{-1.552, -1.772},
	{-1.13, 0.08},
	{-0.428, -1.52},
	{0.426, -0.716},
	};

	return (init_complex(presets[preset][0], presets[preset][1]));
}

void	set_buffalo(t_mlx *mlx)
{
	mlx->fractal.set = BUFFALO;
	mlx->fractal.start = init_complex(-2.1, 2.1);
	mlx->fractal.end = init_complex(2.1, -2.1);
	mlx->fractal.sequence = buffalo;
	mlx->fractal.offset_coor = init_complex(-125, -122);
	mlx->fractal.start_animation = init_complex(-1, 1);
	mlx->fractal.preset = preset_buffalo;
	mlx->fractal.max_preset = PRESET_9;
	mlx->fractal.color = BLUE_RED;
	mlx->fractal.name = "Buffalo";
	mlx->fractal.offset_name = 25;
	mlx->fractal.size_zoom = 1.85;
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

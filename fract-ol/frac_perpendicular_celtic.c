/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_perpendicular_celtic.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:41:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:41:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_pastel_pink(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0xFFB3CB}, {0xF7FFAE}, {0x96FBC7}, {0x74569B}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0xD8BFD8;
		app = new_app;
	}
	return (pal);
}

static t_co	preset_perpendicular_celtic(t_preset preset)
{
	static double	presets[7][2] = {
	{0.80, 0},
	{0.75, 0.13},
	{0.82, -0.2},
	{0.76, 0.06},
	{0.18, 0.69},
	{0.76, -0.32},
	{0.8, -0.14},
	};

	return (init_complex(presets[preset][0], presets[preset][1]));
}

void	set_perpendicular_celtic(t_mlx *mlx)
{
	mlx->fractal.set = PERPENDICULAR_CELTIC;
	mlx->fractal.start = init_complex(-2, 2);
	mlx->fractal.end = init_complex(2, -2);
	mlx->fractal.sequence = perpendicular_celtic;
	mlx->fractal.offset_coor = init_complex(-130, -130);
	mlx->fractal.preset = preset_perpendicular_celtic;
	mlx->fractal.max_preset = PRESET_6;
	mlx->fractal.color = PASTEL_PINK;
	mlx->fractal.name = "Perpendicular Celtic";
	mlx->fractal.offset_name = 60;
	mlx->fractal.c = init_complex(-0.750000, -0.090000);
}

int	perpendicular_celtic(t_mlx *mlx, t_fractal frac, t_co z)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = -2 * fabs(z.x) * z.y + frac.c.y;
		z.x = fabs(sqr.x - sqr.y) + frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}

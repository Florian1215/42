/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:29:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:29:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_purple(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0xB6696A}, {0xE8ECF4}, {0xE1E2E5}, {0xE7CE8C}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0x23254C;
		app = new_app;
	}
	return (pal);
}

t_co	preset_julia(t_preset preset)
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

void	set_julia(t_mlx *mlx)
{
	mlx->fractal.set = JULIA;
	mlx->fractal.sequence = julia;
	mlx->fractal.offset_coor = init_complex(-125, -125);
	mlx->fractal.preset = preset_julia;
	mlx->fractal.max_preset = PRESET_6;
	mlx->fractal.color = PURPLE;
	mlx->fractal.name = "Julia";
	mlx->fractal.offset_name = 19;
}

int	julia(t_mlx *mlx, t_fractal frac, t_co z)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = 2 * z.x * z.y - frac.c.y;
		z.x = sqr.x - sqr.y - frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}

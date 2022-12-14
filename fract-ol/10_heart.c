/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_heart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:41:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:41:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_night_blue(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0x494D7E}, {0xC69FA5}, {0xF2D3AB}, {0xFBF5EF}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0x272744;
		// 0x8B6D9C
		app = new_app;
	}
	return (pal);
}

static t_co	preset_heart(t_preset preset)
{
	static double	presets[6][2] = {
	{-0.07, 0.278},
	{-0.51, 0.085},
	{-0.982, -0.066},
	{0.29, 0.008},
	{-0.108, -0.26},
	{0.29, -0.012},
	};

	return (init_complex(presets[preset][0], presets[preset][1]));
}

void	set_heart(t_mlx *mlx)
{
	mlx->fractal.set = HEART;
	mlx->fractal.sequence = heart;
	mlx->fractal.offset_coor = init_complex(-125, -180);
	mlx->fractal.start_animation = init_complex(-1, 2);
	mlx->fractal.preset = preset_heart;
	mlx->fractal.max_preset = PRESET_5;
	mlx->fractal.color = NIGHT_BLUE;
	mlx->fractal.name = "Heart";
	mlx->fractal.offset_name = 18;
}

int	heart(t_mlx *mlx, t_fractal frac, t_co z)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = 2 * fabs(z.x) * z.y + frac.c.y;
		z.x = sqr.x - sqr.y + frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}

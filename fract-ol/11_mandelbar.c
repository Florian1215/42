/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:45:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:45:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_blue(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0xB5F5EC}, {0x5BACE3}, {0x636AB8}, {0x574175}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0xF7FFED;
		// tEST WITH 040821
		app = new_app;
	}
	return (pal);
}

static t_co	preset_mandelbar(t_preset preset)
{
	static double	presets[8][2] = {
	{-0.23, 0.796},
	{-0.272, -0.776},
	{-0.768, -0.296},
	{-0.132, -0.796},
	{-0.352, -0.746},
	{0.416, -0.526},
	{-0.574, -0.506},
	{-0.78, 0.186},
	};

	return (init_complex(presets[preset][0], presets[preset][1]));
}

void	set_mandelbar(t_mlx *mlx)
{
	mlx->fractal.set = MANDELBAR;
	mlx->fractal.sequence = mandelbar;
	mlx->fractal.offset_coor = init_complex(-125, -100);
	mlx->fractal.start_animation = init_complex(-2, 2);
	mlx->fractal.preset = preset_mandelbar;
	mlx->fractal.max_preset = PRESET_7;
	mlx->fractal.color = BLUE;
	mlx->fractal.name = "Mandelbar";
	mlx->fractal.offset_name = 30;
}

int	mandelbar(t_mlx *mlx, t_fractal frac, t_co z)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = -2 * fabs(z.x) * z.y + frac.c.y;
		z.x = sqr.x - sqr.y + frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}

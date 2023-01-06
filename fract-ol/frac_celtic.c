/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_celtic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:30:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:30:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_electric_blue(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0x007882}, {0x23AA8F}, {0x86D780}, {0xFAFA6E}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0x2A4858;
		app = new_app;
	}
	return (pal);
}

void	set_celtic(t_mlx *mlx)
{
	mlx->fractal.set = CELTIC;
	mlx->fractal.start = init_complex(-2, 1.3);
	mlx->fractal.end = init_complex(2, -2.7);
	mlx->fractal.sequence = celtic;
	mlx->fractal.offset_coor = init_complex(-125, -218);
	mlx->fractal.preset = preset_default;
	mlx->fractal.max_preset = PRESET_0;
	mlx->fractal.color = ELECTRIC_BLUE;
	mlx->fractal.name = "Celtic";
	mlx->fractal.offset_name = 18;
	mlx->fractal.size_zoom = 1.7;
}

int	celtic(t_mlx *mlx, t_fractal frac, t_co c)
{
	int		i;
	t_co	z;
	t_co	sqr;

	i = -1;
	z = init_complex(c.x, c.y);
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = (2 * z.x * z.y) + c.x + frac.c.x;
		z.x = fabs(sqr.x - sqr.y) + c.y + fabs(frac.c.y);
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}
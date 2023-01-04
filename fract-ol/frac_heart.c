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

void	set_heart(t_mlx *mlx)
{
	mlx->fractal.set = HEART;
	mlx->fractal.start = init_complex(-2, 2);
	mlx->fractal.end = init_complex(2, -2);
	mlx->fractal.sequence = heart;
	mlx->fractal.coor = init_complex(-125, -180);
	mlx->fractal.color = NIGHT_BLUE;
	mlx->fractal.name = "Heart";
	mlx->fractal.diff = 18;
	mlx->fractal.c = init_complex(-0.030000, 0.300000);
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

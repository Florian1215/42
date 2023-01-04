/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_celtic_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:38:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/02 12:38:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// LEOPAR KEEP
//0x73383E
//0xAD5845
//0xCF784C
//0xE8AD80
//0xF5E5BF - 0XF7FFed

t_color	*set_yellow(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0xE8AD80}, {0xCF784C}, {0xAD5845}, {0x73383E}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0xF5E5BF;
		app = new_app;
	}
	return (pal);
}

void	set_celtic_mandelbrot(t_mlx *mlx)
{
	mlx->fractal.set = CELTIC_MANDELBROT;
	mlx->fractal.start = init_complex(-2, 2);
	mlx->fractal.end = init_complex(2, -2);
	mlx->fractal.sequence = celtic_mandelbrot;
	mlx->fractal.coor = init_complex(-125, -125);
	mlx->fractal.color = YELLOW;
	mlx->fractal.name = "Celtic Mandelbrot";
	mlx->fractal.diff = 60;
	mlx->fractal.c = init_complex(-0.852000, 0.128000);
}

int	celtic_mandelbrot(t_mlx *mlx, t_fractal frac, t_co z)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = 2 * z.x * z.y + frac.c.y;
		z.x = fabs(sqr.x - sqr.y) + frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:49:33 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/10 10:49:34 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_mlx *mlx, t_fractal frac, t_co c)
{
	t_co	z;
	int		i;
	t_co	sqr;

	z = init_complex(frac.c.x, frac.c.y);
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	i = -1;
	while (++i < frac.max_iter)
	{
		z.y = 2 * z.x * z.y + c.y;
		z.x = sqr.x - sqr.y + c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
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

int	burning_shipe(t_mlx *mlx, t_fractal frac, t_co c)
{
	t_co	z;
	t_co	sqr;
	int		i;

	z = init_complex(frac.c.x, frac.c.y);
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	i = -1;
	while (++i < frac.max_iter)
	{
		z.y = 2 * fabs(z.x * z.y) + c.y;
		z.x = sqr.x - sqr.y + c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
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

int	buffalo(t_mlx *mlx, t_fractal frac, t_co z)
{
	int		i;
	t_co	sqr;

	i = -1;
	sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
	while (++i < frac.max_iter)
	{
		z.y = 2 * fabs(z.x * z.y) + frac.c.y;
		//-2 * z.x * z.y + frac.c.y
		z.x = fabs(sqr.x - sqr.y) + frac.c.x;
		sqr = init_complex(pow(z.x, 2), pow(z.y, 2));
		if (sqr.x + sqr.y > 4)
			return (get_color(mlx, frac, i, sqr.x + sqr.y));
	}
	return (FG);
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

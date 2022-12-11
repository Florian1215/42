#include "fractol.h"

static int	get_pos(t_mlx *mlx, int pos, int diff)
{
	return ((mlx->size.x / 4) * pos - diff);
}

void	select_menu(t_mlx *mlx, t_co co)
{
	t_co	half_size;

	if (mlx->in_menu)
	{
		half_size = init_coor(mlx->size.x / 2, mlx->size.y / 2);
		if (co.x < half_size.x && co.y < half_size.y)
			mlx->fractol = mandelbrot;
		else if (co.x > half_size.x && co.y < half_size.y)
		{
			printf("Julia Select\n");
			mlx->fractol = julia;
		}
		else if (co.x < half_size.x && co.y > half_size.y)
			printf("Celtic Select\n");
		else if (co.x > half_size.x && co.y > half_size.y)
			printf("Burning Ship Select\n");
		fractol(mlx);
		mlx->in_menu = 0;
	}
}

t_fractal	init_frac(enum e_fractal set, t_co start, t_co end, float (*func)(t_mlx *, t_co))
{
	t_fractal	frac;

	frac.set = set;
	frac.start = start;
	frac.end = end;
	frac.func = func;
	return (frac);
}

t_co	convert_co(t_fractal frac, t_co i)
{
	t_co	co;

	if (frac.set == MANDELBROT)
	{
		co = init_coor(
						((i.x - (frac.end.x / 2) - 80) / (frac.end.x / 2)) * 1.5,
						((i.y - (frac.end.y / 2)) / (frac.end.y / 2)) * 1.5);
	}
	else //if (frac.set == JULIA)
	{
		co = init_coor(
						((i.x - ((frac.end.x - frac.start.x) * 2) + 100) / ((frac.end.x - frac.start.x) / 2)) * (200 / 100),
						((i.y - (frac.end.y / 2)) / (frac.end.y / 2)) * (200 / 100));
	}
	return (co);
}

void	fractol_preview(t_mlx *mlx, t_fractal frac)
{
	t_co	i;
	double	color;
	float	res;

	i.x = frac.start.x - 1;
	//printf("FUNC CALL | start x = %f - start y = %f | end x = %f - end y = %f\n", start.x, start.y, end.x, end.y);
	while (++i.x < frac.end.x)
	{
		i.y = frac.start.y - 1;
		while (++i.y < frac.end.y)
		{
			//printf("%f -> %f | end = %f - start = %f\n", i.x, ((i.x - ((end.x - start.x) / 2) + start.x) / ((end.x - start.x) / 2)), end.x, start.x);
			res = frac.func(mlx, convert_co(frac, i));
			color = get_gradient(mlx, res);
			mlx_put_pixel_img(&mlx->img, i, color);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}

void	set_menu(t_mlx *mlx)
{

	fractol_preview(mlx, init_frac(MANDELBROT, init_coor(0, 0), init_coor(mlx->size.x / 2, mlx->size.x / 2), &mandelbrot));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos(mlx, 1, 30), get_pos(mlx, 1, -3), 0xFFFFFF, "Mandelbrot");
	set_color(mlx, 1);
	fractol_preview(mlx, init_frac(JULIA, init_coor(mlx->size.x / 2, 0), init_coor(mlx->size.x, mlx->size.x / 2), &julia));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos(mlx, 3, 15), get_pos(mlx, 1, -3), 0xFFFFFF, "Julia");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos(mlx, 1, 18), get_pos(mlx, 3, -3), 0xFFFFFF, "Celtic");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, get_pos(mlx, 3, 36), get_pos(mlx, 3, -3), 0xFFFFFF, "Burning Ship");
}

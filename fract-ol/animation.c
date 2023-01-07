/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:33:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/06 10:33:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	c_animation(t_mlx *mlx)
{
	static double	values[29] = {0.4, 1.7, 4.6, 9.8, 19, 32, 44.7, 54.7, 62.4, 68.6, 73.6, 77.7, 81.2, 84.2, 86.8, 89, 90.9, 92.5, 93.9, 95.2, 96.2, 97.1, 97.8, 98.5, 99, 99.4, 99.6, 99.8, 99.9};
	static int		i = 0;

	if (i == 29)
	{
		i = 0;
		mlx->c_animate = 0;
		mlx->fractal.c = mlx->fractal.end_animation;
		fractal_render(mlx);
		return ;
	}
	if (mlx->fractal.start_animation.y > mlx->fractal.end_animation.y)
		mlx->fractal.c.y = mlx->fractal.start_animation.y - (values[i] * (mlx->fractal.start_animation.y - mlx->fractal.end_animation.y) / 100);
	else if (mlx->fractal.start_animation.y < mlx->fractal.end_animation.y)
		mlx->fractal.c.y = (values[i] * (mlx->fractal.end_animation.y - mlx->fractal.start_animation.y) / 100) + mlx->fractal.start_animation.y;
	if (mlx->fractal.start_animation.x > mlx->fractal.end_animation.x)
		mlx->fractal.c.x = mlx->fractal.start_animation.x - (values[i] * (mlx->fractal.start_animation.x - mlx->fractal.end_animation.x) / 100);
	else if (mlx->fractal.start_animation.x < mlx->fractal.end_animation.x)
		mlx->fractal.c.x = (values[i] * (mlx->fractal.end_animation.x - mlx->fractal.start_animation.x) / 100) + mlx->fractal.start_animation.x;
//	printf("% f % f\n", mlx->fractal.c.x, mlx->fractal.c.y);
	fractal_render(mlx);
	i++;
}

void	hover_animation(t_mlx *mlx)
{
	static double	values[9] = {0, 0.01, 0.04, 0.08, 0.10, 0.115, 0.119, 0.127, 0.13};

	if (mlx->hover.pos != POS_ERROR && mlx->hover.i < 9)
		mlx->hover.value = 1 - values[mlx->hover.i++];
	if (mlx->prev_hover.pos != POS_ERROR && mlx->prev_hover.i < 9)
		mlx->prev_hover.value = 1 - values[8] + values[mlx->prev_hover.i++];
	set_menu(mlx);
}

void	render_slide(t_mlx *mlx)
{
//	static int	values[21] = {0, 9, 43, 131, 307, 492, 620, 710, 775, 827, 867, 899, 924, 946, 962, 975, 985, 992, 996, 999, 1000};
	static int	values[30] = {4, 17, 46, 98, 190, 320, 447, 547, 624, 686, 736, 777, 812, 842, 868, 890, 909, 925, 939, 952, 962, 971, 978, 985, 990, 994, 996, 998, 999, 1000};
//	static int	values[26] = {0, 6, 26, 73, 168, 320, 469, 580, 663, 727, 777, 819, 853, 881, 905, 925, 942, 956, 968, 977, 985, 990, 995, 998, 999, 1000};
	static int	i = 0;
	int			x_img;
	int			x_slide;
	int			tmp;

	if (i == 30)
	{
		i = 0;
		mlx->slide.start = 0;
		mlx->slide.slide = 0;
		return ;
	}
	tmp = values[i] * mlx->size / values[29];
	x_img = mlx->slide.side == RIGHT ? mlx->size - tmp : tmp - mlx->size;
	x_slide = mlx->slide.side == RIGHT ? 0 - tmp : tmp;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, x_img, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->slide.img.img, x_slide, 0);
	set_name_fractals(mlx, x_img);
	i++;
}

void	slide_page(t_mlx *mlx, t_keycode side)
{
	mlx->slide.slide = 1;
	mlx->slide.save = 1;
	set_menu(mlx);
	mlx->slide.save = 0;
	mlx->slide.side = side;
	if (side == LEFT)
		set_page(mlx, mlx->page - 1);
	else
		set_page(mlx, mlx->page + 1);
	set_menu(mlx);
	mlx->slide.start = 1;
}

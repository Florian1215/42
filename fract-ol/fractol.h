/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:37:22 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/12 16:23:26 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# include <stdio.h>

# define MAX_THREADS 8

struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

typedef struct s_co
{
	double	x;
	double	y;
}				t_co;

enum e_keycode
{
	C = 8,
	D = 2,
	Q = 12,
	ESQ = 53,
	TAB = 48,
	R = 15,
	F = 3,
	T = 17,
	G = 5,
	RIGHT = 123,
	LEFT = 124,
	DOWN = 125,
	UP = 126
};

enum e_mousecode
{
	LEFT_CLICK = 1,
	SCROLL_IN = 4,
	SCROLL_OUT = 5,
};

typedef enum e_fractal
{
	MANDELBROT,
	JULIA,
	CELTIC,
	BURNING_SHIP,
}			t_fractals;

typedef enum e_colors
{
	GREEN,
	YELLOW,
	BLUE,
	RED,
	GREY,
}			t_colors;

typedef struct s_color
{
	int			c1;
	int			c2;
	int			c3;
	t_colors	set;
}				t_color;

typedef struct s_fractal
{
	t_fractals	set;
	t_co		start;
	t_co		end;
	int			(*func)(void *, t_co);
	t_colors	color;
}				t_fractal;

struct	s_hover
{
	t_fractals	set;
	double		value;
};

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			max_iter;
	struct s_img	img;
	t_fractal		fractal;
	t_co			size;
	t_co			c;
	t_co			prev_pos;
	t_color			color;
	struct s_hover	hover;
	struct s_hover	prev_hover;
	int				dark_mode;
	int				launch;
	int				moving;
	int				in_menu;
	int				render;
}				t_mlx;

typedef struct s_thread
{
	t_mlx		*mlx;
	pthread_t	thread;
	int			id;
}				t_thread;

typedef struct s_preview_thread
{
	t_mlx		*mlx;
	pthread_t	thread;
	t_fractal	frac;
	t_color		color;
}				t_preview_thread;

// FRACTAL
void		fractal_render(t_mlx *mlx);
void		create_fractal(t_thread	*t);
void		move(t_mlx *mlx, enum e_keycode side);
void		zoom(t_mlx *mlx, double scale, t_co co);
void		edit_c(t_mlx *mlx, double j, double *nb);
t_fractal	init_fractal(t_fractals set, t_co start, t_co end, \
	int (*func)(t_mlx *, t_co), t_colors color);
void		set_fractal(t_mlx *mlx, t_fractals set);
int			mandelbrot(t_mlx *mlx, t_co c);
int			julia(t_mlx *mlx, t_co z);
int			burning_shipe(t_mlx *mlx, t_co c);
int			celtic(t_mlx *mlx, t_co c);

// MENU
void		set_menu(t_mlx *mlx);
t_fractals	select_fractal(t_mlx *mlx, t_co co);
void		init_hover(t_mlx *mlx);
int			mouse_event_motion(int x, int y, t_mlx *mlx);

// UTILS
t_co		init_coor(double x, double y);
int			close_mlx(t_mlx *mlx);

// MLX
void		init_mlx(t_mlx **mlx);
void		mlx_put_pixel_img(struct s_img *img, t_co co, int color);

// HOOK
void		set_hook(t_mlx *mlx);
int			loop(t_mlx *mlx);

// COLOR
int			get_color(t_color color, double r, int dark_mode);
void		toggle_dark_mode(t_mlx *mlx);
t_color		init_color(int c1, int c2, int c3, t_colors set);
void		set_color(t_mlx *mlx, t_colors color);
void		set_1(t_mlx *mlx);
void		set_2(t_mlx *mlx);
void		set_3(t_mlx *mlx);
void		set_4(t_mlx *mlx);
void		set_5(t_mlx *mlx);

#endif
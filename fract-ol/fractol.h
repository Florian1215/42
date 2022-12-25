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

//TYPEDEF
typedef enum e_colors			t_colors;
typedef union u_color			t_color;
typedef enum e_appearance		t_appearance;
typedef struct s_co				t_co;
typedef struct s_mlx			t_mlx;
typedef struct s_fractal		t_fractal;
typedef enum e_fractal			t_fractals;
typedef struct s_thread			t_thread;
typedef struct s_preview_thread	t_preview_thread;

//UTILS
struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_co
{
	double	x;
	double	y;
};

int			close_mlx(t_mlx *mlx);
void		init_mlx(t_mlx **mlx);
void		mlx_put_pixel_img(struct s_img *img, t_co co, int color);
t_co		init_coor(double x, double y);

// COLOR
enum e_color_hex
{
	FG = 0x222222,
	WHITE = 0xFFFFFF,
};

enum e_colors
{
	GREEN,
	PURPLE,
	BLUE,
	RED,
	BLUE_RED,
	PINK,
};

enum e_appearance
{
	LIGHT,
	DARK,
};

struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
};

union u_color
{
	unsigned int	color;
	struct s_rgb	rgb;
};

int			get_color(t_mlx *mlx, int i, double sqr, t_colors set);
void		toggle_appearance(t_mlx *mlx);
void		edit_color(t_mlx *mlx);
void		set_color(t_mlx *mlx, t_colors color);
t_color		*set_1(t_appearance new_app);
t_color		*set_2(t_appearance new_app);
t_color		*set_3(t_appearance new_app);
t_color		*set_4(t_appearance new_app);
t_color		*set_5(t_appearance new_app);
t_color		*set_6(t_appearance new_app);

// HOOK
enum e_keycode
{
	C = 8,
	D = 2,
	Q = 12,
	ESQ = 53,
	TAB = 48,
	PLUS = 69,
	MINUS = 78,
	RIGHT = 123,
	LEFT = 124,
	DOWN = 125,
	UP = 126,
};

enum e_mousecode
{
	LEFT_CLICK = 1,
	SCROLL_IN = 4,
	SCROLL_OUT = 5,
};

void		set_hook(t_mlx *mlx);
int			loop(t_mlx *mlx);

// FRACTAL
enum e_fractal
{
	MANDELBROT,
	JULIA,
	CELTIC,
	BURNING_SHIP,
};

struct s_fractal
{
	t_fractals	set;
	t_co		start;
	t_co		end;
	t_colors	color;
	int			(*func)(void *, t_co, t_colors);
};

struct	s_hover
{
	t_fractals	set;
	double		value;
};

struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			max_iter;
	struct s_img	img;
	t_fractal		fractal;
	t_co			size;
	t_co			c;
	t_co			prev_pos;
	struct s_hover	hover;
	struct s_hover	prev_hover;
	t_appearance	appearance;
	int				launch;
	int				moving;
	int				in_menu;
	int				offset_color;
	t_colors		color;
};

void		fractal_render(t_mlx *mlx);
void		create_fractal(t_thread	*t);
void		zoom(t_mlx *mlx, double scale, t_co co);
void		edit_c(t_mlx *mlx, double j, double *nb);
void		edit_iter(t_mlx *mlx, double j);
t_fractal	init_fractal(t_fractals set, t_co start, t_co end, \
	int (*func)(t_mlx *, t_co, t_colors), t_colors color);
void		set_fractal(t_mlx *mlx, t_fractals set);
int			mandelbrot(t_mlx *mlx, t_co c, t_colors color_set);
int			julia(t_mlx *mlx, t_co z, t_colors color_set);
int			burning_shipe(t_mlx *mlx, t_co c, t_colors color_set);
int			celtic(t_mlx *mlx, t_co c, t_colors color_set);
int			julia3(t_mlx *mlx, t_co z, t_colors color_set);

// THREAD
struct s_thread
{
	t_mlx		*mlx;
	pthread_t	thread;
	int			id;
};

struct s_preview_thread
{
	t_mlx		*mlx;
	pthread_t	thread;
	t_fractal	frac;
};

// MENU
void		set_menu(t_mlx *mlx);
t_fractals	select_fractal(t_mlx *mlx, t_co co);
void		init_hover(t_mlx *mlx);
int			mouse_event_motion(int x, int y, t_mlx *mlx);

#include <stdio.h>


#endif
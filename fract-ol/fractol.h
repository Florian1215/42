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

//TYPEDEF --------------------------------------
typedef enum e_pos				t_pos;
typedef enum e_bool				t_bool;
typedef enum e_colors			t_colors;
typedef enum e_preset			t_preset;
typedef enum e_keycode			t_keycode;
typedef enum e_fractal			t_fractals;
typedef enum e_appearance		t_appearance;
typedef union u_color			t_color;
typedef struct s_co				t_co;
typedef struct s_mlx			t_mlx;
typedef struct s_img			t_img;
typedef struct s_slide			t_slide;
typedef struct s_hover			t_hover;
typedef struct s_thread			t_thread;
typedef struct s_fractal		t_fractal;
typedef struct s_preview_thread	t_preview_thread;

//UTILS ----------------------------------------
enum e_bool
{
	FALSE,
	TRUE,
};

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

enum e_pos
{
	POS_ERROR = -1,
	POS_1,
	POS_2,
	POS_3,
	POS_4,
};

int			close_mlx(t_mlx *mlx);
void		init_mlx(t_mlx *mlx);
void		mlx_put_pixel_img(t_img *img, t_co co, int color);
t_co		init_complex(double x, double y);

// COLOR ---------------------------------------
enum e_color_hex
{
	FG = 0x202020,
	WHITE = 0xFFFFFF,
};

enum e_colors
{
	GREEN,
	PURPLE,
	ELECTRIC_BLUE,
	RED,
	BLUE_RED,
	PINK,
	GREEN_BLUE,
	BLUE_LIGHT,
	PASTEL_PINK,
	NIGHT_BLUE,
	BLUE,
	YELLOW,
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

int			get_color(t_mlx *mlx, t_fractal frac, int i, double sqr);
void		toggle_appearance(t_mlx *mlx);
void		edit_color(t_mlx *mlx);
void		set_color(t_mlx *mlx, t_colors color);
t_color		*set_green(t_appearance new_app);
t_color		*set_purple(t_appearance new_app);
t_color		*set_electric_blue(t_appearance new_app);
t_color		*set_red(t_appearance new_app);
t_color		*set_blue_red(t_appearance new_app);
t_color		*set_pink(t_appearance new_app);
t_color		*set_green_blue(t_appearance new_app);
t_color		*set_blue_light(t_appearance new_app);
t_color		*set_pastel_pink(t_appearance new_app);
t_color		*set_night_blue(t_appearance new_app);
t_color		*set_blue(t_appearance new_app);
t_color		*set_yellow(t_appearance new_app);

// HOOK ----------------------------------------
enum e_keycode
{
	C = 8,
	D = 2,
	Q = 12,
	W = 13,
	E = 14,
	ESQ = 53,
	TAB = 48,
	SPACE = 49,
	PLUS = 69,
	MINUS = 78,
	LEFT = 123,
	RIGHT = 124,
	DOWN = 125,
	UP = 126,
	NUM_0 = 82,
	NUM_1 = 83,
	NUM_2 = 84,
	NUM_3 = 85,
	NUM_4 = 86,
	NUM_5 = 87,
	NUM_6 = 88,
	NUM_7 = 89,
	NUM_8 = 91,
	NUM_9 = 92,
};

enum e_mousecode
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	SCROLL_IN = 4,
	SCROLL_OUT = 5,
};

void		set_hook(t_mlx *mlx);
int			mouse_event_press(int button, int x, int y, t_mlx *mlx);
int			mouse_event_release(int button, int x, int y, t_mlx *mlx);
int			mouse_event_motion(int x, int y, t_mlx *mlx);

// MENU ----------------------------------------
struct s_slide
{
	t_img		img;
	t_keycode	side;
	int			i;
	t_bool		slide;
	t_bool		start;
	t_bool		save;
};

void		set_menu(t_mlx *mlx);
void		set_name_fractals(t_mlx *mlx, void *img, int x_offset);
t_pos		select_fractal(t_mlx *mlx, t_co co);
void		init_hover(t_mlx *mlx);
int			mouse_event_motion(int x, int y, t_mlx *mlx);
void		set_page(t_mlx *mlx, int page);
void		slide_page(t_mlx *mlx, t_keycode side);
void		render_slide(t_mlx *mlx);
void		hover_animation(t_mlx *mlx);

// FRACTAL -------------------------------------
enum e_fractal
{
	MANDELBROT,
	JULIA,
	CELTIC,
	BURNING_SHIP,
	BUFFALO,
	BURNING_JULIA,
	JULIA3,
	CELTIC_MANDELBAR,
	PERPENDICULAR_CELTIC,
	HEART,
	MANDELBAR,
	CELTIC_MANDELBROT,
};

enum e_preset
{
	PRESET_0,
	PRESET_1,
	PRESET_2,
	PRESET_3,
	PRESET_4,
	PRESET_5,
	PRESET_6,
	PRESET_7,
	PRESET_8,
	PRESET_9,
};

struct s_fractal
{
	t_fractals	set;
	t_colors	color;
	t_co		c;
	t_co		start;
	t_co		end;
	t_co		start_animation;
	t_co		end_animation;
	t_co		start_launch;
	t_co		end_launch;
	char		*name;
	int			offset_name;
	int			max_iter;
	double		size_zoom;
	t_co		offset_coor;
	t_preset	max_preset;
	t_co		(*preset)(t_preset);
	int			(*sequence)(t_mlx *, t_fractal, t_co);
};

struct	s_hover
{
	t_pos	pos;
	double	value;
	int		i;
};

struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_hover			hover;
	t_hover			prev_hover;
	t_appearance	appearance;
	t_fractals		menu[4];
	t_fractal		fractal;
	t_colors		color;
	t_co			prev_pos;
	int				size;
	int				offset_color;
	int				page;
	t_bool			c_animate;
	t_bool			launch;
	t_bool			reset;
	t_bool			moving;
	t_bool			in_menu;
	t_bool			edit_c;
	t_bool			render;
	t_slide			slide;
};

void		fractal_render(t_mlx *mlx);
void		create_fractal(t_thread	*t);
void		c_animation(t_mlx *mlx);
void		launch_fractal(t_mlx *mlx, t_fractals set);
void		reset_animation(t_mlx *mlx);
void		zoom(t_mlx *mlx, double scale, t_co co);
void		set_preset(t_mlx *mlx, t_preset preset);
void		edit_c(t_mlx *mlx, double j, double *nb);
void		edit_iter(t_mlx *mlx, double j);
void		set_fractal(t_mlx *mlx, t_fractals set);
void		move(t_mlx *mlx, int x, int y);

int			mandelbrot(t_mlx *mlx, t_fractal frac, t_co c);
int			julia(t_mlx *mlx, t_fractal frac, t_co z);
int			burning_shipe(t_mlx *mlx, t_fractal frac, t_co c);
int			celtic(t_mlx *mlx, t_fractal frac, t_co c);
int			buffalo(t_mlx *mlx, t_fractal frac, t_co z);
int			burning_julia(t_mlx *mlx, t_fractal frac, t_co c);
int			julia3(t_mlx *mlx, t_fractal frac, t_co z);
int			celtic_mandelbar(t_mlx *mlx, t_fractal frac, t_co z);
int			perpendicular_celtic(t_mlx *mlx, t_fractal frac, t_co z);
int			heart(t_mlx *mlx, t_fractal frac, t_co z);
int			mandelbar(t_mlx *mlx, t_fractal frac, t_co z);
int			celtic_mandelbrot(t_mlx *mlx, t_fractal frac, t_co z);

void		set_mandelbrot(t_mlx *mlx);
void		set_julia(t_mlx *mlx);
void		set_celtic(t_mlx *mlx);
void		set_burning_shipe(t_mlx *mlx);
void		set_buffalo(t_mlx *mlx);
void		set_burning_julia(t_mlx *mlx);
void		set_julia3(t_mlx *mlx);
void		set_celtic_mandelbar(t_mlx *mlx);
void		set_perpendicular_celtic(t_mlx *mlx);
void		set_heart(t_mlx *mlx);
void		set_mandelbar(t_mlx *mlx);
void		set_celtic_mandelbrot(t_mlx *mlx);

// THREAD --------------------------------------
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

#include <stdio.h>
#include <unistd.h>

#endif
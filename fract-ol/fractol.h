/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:37:22 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/05 14:41:24 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>

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

struct	s_zoom
{
	t_co	start;
	t_co	end;
	double	scale;
};

enum e_keycode
{
	S = 1,
	C = 8,
	Q = 12,
	W = 13,
	J = 38,
	ESQ = 53,
	PLUS = 69,
	MINUS = 78,
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

enum e_fractal
{
	MANDELBROT,
	JULIA,
	CELTIC,
	BURNING_SHIP,
};

enum e_colors
{
	GREEN,
	RED,
	BLUE,
	PURPLE,
	YELLOW,
};

typedef struct	s_color
{
	int	fg;
	int	bg;
	int	c1;
	int	c2;
}				t_color;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					max_iter;
	t_co				size;
	struct s_zoom		zoom;
	struct s_img		img;
	t_color				color;
	enum e_colors		color_set;
	int					in_menu;
	float				(*fractol)(struct s_mlx *, t_co);

}				t_mlx;

typedef struct s_fractal
{
	enum e_fractal	set;
	t_co			start;
	t_co			end;
	float			(*func)(struct s_mlx *, t_co);
}				t_fractal;

// FRACTAL
void		fractol(t_mlx *mlx);
void		move(t_mlx *mlx, enum e_keycode side);
void		zoom(t_mlx *mlx, double scale, t_co co);
void		edit_iter(t_mlx *mlx, int iter);
float	mandelbrot(t_mlx *mlx, t_co c);
float	julia(t_mlx *mlx, t_co z);
float	burning_shipe(t_mlx *mlx, t_co c);
float	celtic(t_mlx *mlx, t_co c);

// MENU
void		set_menu(t_mlx *mlx);
void		select_menu(t_mlx *mlx, t_co);

// UTILS
t_co		init_coor(double x, double y);
int			close(t_mlx *mlx);

// MLX
void		init_zoom(t_mlx *mlx);
void		init_mlx(t_mlx **mlx);
void		mlx_put_pixel_img(struct s_img *img, t_co co, int color);

// HOOK
int			key_event(int k, t_mlx *mlx);
int			mouse_event(int button, int x, int y, t_mlx *mlx);

// COLOR
int			get_gradient(t_mlx *mlx, double r);
t_color		init_color(int bg, int fg, int c1, int c2);
void		set_color(t_mlx *mlx, int new);
void		set_1(t_mlx *mlx);
void		set_2(t_mlx *mlx);
void		set_3(t_mlx *mlx);
void		set_4(t_mlx *mlx);
void		set_5(t_mlx *mlx);

# include <stdio.h>

#endif
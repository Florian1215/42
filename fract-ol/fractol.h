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

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	unsigned int		size_x;
	unsigned int		size_y;
	unsigned int 		zoom;
	unsigned int		zoom_x;
	unsigned int		zoom_y;
	//int		size_x;
	//int		size_y;
	t_img				img;
}				t_mlx;

// UTILS
int		close(t_mlx *mlx);
void	init_mlx(t_mlx **mlx);
int		get_gradient(double c1, double c2, double r);
void	fast_mlx_pixel_put(t_img *img, int x, int y, int color);

# include <stdio.h>

#endif
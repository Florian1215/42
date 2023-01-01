/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:30:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/01 20:30:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_co	coor_mandelbrot(t_co i, int size, double hover)
{
	t_co	co;

	co.x = ((i.x - (size / 2) - 64) / (size / 2)) * (1.5 * hover);
	co.y = ((i.y - (size / 2)) / (size / 2)) * (1.5 * hover);
	return (co);
}

t_co	coor_julia(t_co i, int size, double hover)
{
	t_co	co;

	co.x = (i.x - (size * 2) + 243) / (size / 2) * (1.5 * hover);
	co.y = ((i.y - (size / 2)) / (size / 2)) * (1.5 * hover);
	return (co);
}

t_co	coor_celtic(t_co i, int size, double hover)
{
	t_co	co;

	co.x = (i.x - (size / 2)) / (size / 2) * (1.8 * hover);
	co.y = (i.y - (size * 2) + 171) / (size / 2) * (1.8 * hover);
	return (co);
}

t_co	coor_burning_ship(t_co i, int size, double hover)
{
	t_co	co;

	co.x = (i.x - (size * 2) + 186) / (size / 2) * (1.6 * hover);
	co.y = ((i.y - (size / 2) - 543) / (size / 2)) * (1.6 * hover);
	return (co);
}

t_co	coor_buffalo(t_co i, int size, double hover)
{
	t_co	co;

	co.x = (i.x - (size * 2) + 750) / (size / 2) * (1.6 * hover);
	co.y = ((i.y - (size / 2)) / (size / 2)) * (1.6 * hover);
	return (co);
}

t_co	coor_burning_julia(t_co i, int size, double hover)
{
	t_co	co;

	co.x = (i.x - (size * 2) + 240) / (size / 2) * (1.6 * hover);
	co.y = ((i.y - (size / 2)) / (size / 2)) * (1.6 * hover);
	return (co);
}

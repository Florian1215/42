/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_palettes2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:04:57 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/21 19:05:01 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	set_6(int dark_mode)
{
	t_palette	pal;

	//printf("set 6\n");
	(void)dark_mode;
	pal.colors[0].color = 0x00748E;
	pal.colors[1].color = 0xE3DFBB;
	pal.colors[2].color = 0xF4BA4D;
	pal.colors[3].color = 0xE3753C;
	pal.colors[4].color = 0xDA3B3A;
	pal.set = BLUE_RED;
	return (pal);
}

t_palette	set_7(int dark_mode)
{
	t_palette	pal;

	//printf("set 7\n");
	(void)dark_mode;
	pal.colors[0].color = 0x7DBEA5;
	pal.colors[1].color = 0xF1E0B1;
	pal.colors[2].color = 0xEE9D31;
	pal.colors[3].color = 0xF26C1A;
	pal.colors[4].color = 0x5A392B;
	pal.set = BLUE_RED;
	return (pal);
}

t_palette	set_8(int dark_mode)
{
	t_palette	pal;

	//printf("set 8\n");
	(void)dark_mode;
	pal.colors[0].color = 0x405952;
	pal.colors[1].color = 0x9C9B7A;
	pal.colors[2].color = 0xFFD393;
	pal.colors[3].color = 0xFF974F;
	pal.colors[4].color = 0xF54F29;
	pal.set = KHAKI;
	return (pal);
}

t_palette	set_9(int dark_mode)
{
	t_palette	pal;

	//printf("set 9\n");
	(void)dark_mode;
	pal.colors[0].color = 0xFFE9AA;
	pal.colors[1].color = 0xE8CB9A;
	pal.colors[2].color = 0xFFA755;
	pal.colors[3].color = 0xFF6549;
	pal.colors[4].color = 0xFF9B71;
	pal.set = YELLOW;
	return (pal);
}

t_palette	set_10(int dark_mode)
{
	t_palette	pal;

	//printf("set 10\n");
	(void)dark_mode;
	pal.colors[0].color = 0xEEEFE3;
	pal.colors[1].color = 0xBBC7A5;
	pal.colors[2].color = 0x363432;
	pal.colors[3].color = 0x363432;
	pal.colors[4].color = 0x363432;
	pal.set = DARK_BLUE;
	return (pal);
}

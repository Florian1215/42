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

t_palette	set_6(void)
{
	t_palette	pal;

	pal.colors[0].color = 0x1E4147;
	pal.colors[1].color = 0x437356;
	pal.colors[2].color = 0xAAC789;
	pal.colors[3].color = 0xFAE3B4;
	pal.colors[4].color = 0xF34A53;
	pal.set = GREEN;
	return (pal);
}

t_palette	set_7(void)
{
	t_palette	pal;

	pal.colors[0].color = 0xD7572B;
	pal.colors[1].color = 0xDA7B27;
	pal.colors[2].color = 0xFFCA5A;
	pal.colors[3].color = 0xFFCA5A;
	pal.colors[4].color = 0xFFCA5A;
	pal.set = YELLOW;
	return (pal);
}

t_palette	set_8(void)
{
	t_palette	pal;

	pal.colors[0].color = 0xA7DDBC;
	pal.colors[1].color = 0x8FC5AA;
	pal.colors[2].color = 0x316764;
	pal.colors[3].color = 0x316764;
	pal.colors[4].color = 0x316764;
	pal.set = BLUE;
	return (pal);
}

t_palette	set_9(void)
{
	t_palette	pal;

	pal.colors[0].color = 0xC24844;
	pal.colors[1].color = 0xEB5752;
	pal.colors[2].color = 0xFFD0CC;
	pal.colors[3].color = 0xFFD0CC;
	pal.colors[4].color = 0xFFD0CC;
	pal.set = RED;
	return (pal);
}

t_palette	set_10(void)
{
	t_palette	pal;

	pal.colors[0].color = 0xEEEFE3;
	pal.colors[1].color = 0xBBC7A5;
	pal.colors[2].color = 0x363432;
	pal.colors[3].color = 0x363432;
	pal.colors[4].color = 0x363432;
	pal.set = GREY;
	return (pal);
}

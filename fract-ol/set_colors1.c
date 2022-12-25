/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:04:51 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/21 19:04:53 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// GREEN
t_color	*set_1(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {}, {0xFFB03B}, {0xB64926}, {0x8E2800}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
		{
			pal[0].color = FG;
			pal[1].color = 0x295E52;
		}
		else
		{
			pal[0].color = 0x468966;
			pal[1].color = 0xFFF0A5;
		}
		app = new_app;
	}
	return (pal);
}

// PURPLE
t_color	*set_2(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0xB6696A}, {0xE8ECF4}, {0xE1E2E5}, {0xE7CE8C}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0x23254C;
		app = new_app;
	}
	return (pal);
}

// BLUE
t_color	*set_3(t_appearance new_app)
{
	static t_color		pal[5] = {{}, {0x007882}, {0x23AA8F}, {0x86D780}, {0xFAFA6E}};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
			pal[0].color = FG;
		else
			pal[0].color = 0x2A4858;
		app = new_app;
	}
	return (pal);
}

// RED
t_color	*set_4(t_appearance new_app)
{
	static t_color		pal[5] = {};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
		{
			pal[0].color = FG;
			pal[1].color = 0x374140;
			pal[2].color = 0x817A63;
			pal[3].color = 0xD9CB9E;
			pal[4].color = 0xDC3522;
		}
		else
		{
			pal[0].color = 0xF45D4C;
			pal[1].color = 0xF7A541;
			pal[2].color = 0xFACA66;
			pal[3].color = 0xFEE5AD;
			pal[4].color = 0xA1DBB2;
		}
		app = new_app;
	}
	return (pal);
}

// BLUE_RED
t_color	*set_5(t_appearance new_app)
{
	static t_color		pal[5] = {};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
		{
			pal[0].color = FG;
			pal[1].color = 0x263248;
			pal[2].color = 0x7E8AA2;
			pal[3].color = 0xE3DFBB;
			pal[4].color = 0xF0642A;
		}
		else
		{
			pal[0].color = 0x00748E;
			pal[1].color = 0xE3DFBB;
			pal[2].color = 0xF4BA4D;
			pal[3].color = 0xE3753C;
			pal[4].color = 0xDA3B3A;
		}
		app = new_app;
	}
	return (pal);
}

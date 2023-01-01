/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:23:48 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/25 10:23:50 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// PINK
t_color	*set_6(t_appearance new_app)
{
	static t_color		pal[5] = {};
	static t_appearance	app = -1;

	if (app != new_app)
	{
		if (new_app)
		{
			pal[0].color = FG;
			pal[1].color = 0x333F58;
			pal[2].color = 0x4A7A96;
			pal[3].color = 0xEE8695;
			pal[4].color = 0xFBBBAD;
		}
		else
		{
			pal[0].color = 0xEE7788;
			pal[1].color = 0xFFCCCC;
			pal[2].color = 0xFF99AA;
			pal[3].color = 0xCC4466;
			pal[4].color = 0x441122;
		}
		app = new_app;
	}
	return (pal);
}

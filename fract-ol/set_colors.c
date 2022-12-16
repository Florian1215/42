/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:22:37 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:39 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	set_1(void)
{
	return (init_color(GREEN, 0xB9E0A2, 0xA4bE7B, 0x3D663D));
}

t_color	set_2(void)
{
	return (init_color(YELLOW, 0xD7572B, 0xDA7B27, 0xFFCA5A));
}

t_color	set_3(void)
{
	return (init_color(BLUE, 0xA7DDBC, 0x8FC5AA, 0x316764));
}

t_color	set_4(void)
{
	return (init_color(RED, 0xC24844, 0xEB5752, 0xFFD0CC));
}

t_color	set_5(void)
{
	return (init_color(GREY, 0xEEEFE3, 0xBBC7A5, 0x363432));
}

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

#define C1	0x6E5D54
#define C2	0xBB937C
#define C3	0xBBAAA1
#define C4	0x69BBBA
#define C5	0x526D6D

//#define C1	0x051E21
//#define C2	0x00302D
//#define C3	0x856434
//#define C4	0xF28C28
//#define C5	0xFFAD4E

//#define C1	0x00748E
//#define C2	0xE3DFBB
//#define C3	0xF4BA4D
//#define C4	0xE3753C
//#define C5	0xDA3B3A

//#define C1	0xA1DBB2
//#define C2	0xFEE5AD
//#define C3	0xFACA66
//#define C4	0xF7A541
//#define C5	0xF45D4C

//#define C1	0xFF6138
//#define C2	0xFFFF9D
//#define C3	0xBEEB9F
//#define C4	0x79BD8F
//#define C5	0x00A388

//#define C1	0x003354
//#define C2	0x91BED4
//#define C3	0xD9E8F5
//#define C4	0xFFFFFF
//#define C5	0xF26101

//#define C1	0x405952
//#define C2	0x9C9B7A
//#define C3	0xFFD393
//#define C4	0xFF974F
//#define C5	0xF54F29

//#define C1	0x7DBEA5
//#define C2	0xF1E0B1
//#define C3	0xEE9D31
//#define C4	0xF26C1A
//#define C5	0x5A392B

// RED DARk
//#define C1	0xDC3522
//#define C2	0xD9CB9E
//#define C3	0x374140
//#define C4	0x2A2C2B
//#define C5	0x1E1E20

//#define C1	0x225378
//#define C2	0x1695A3
//#define C3	0xACF0F2
//#define C4	0xF3FFE2
//#define C5	0xEB7F00
//ORANGE - BLEU

t_palette	set_1(void)
{
	t_palette	pal;

//	pal.colors[0].color = 0x00A388;
//	pal.colors[1].color = 0x79BD8F;
//	pal.colors[2].color = 0xBEEB9F;
//	pal.colors[3].color = 0xFFFF9D;
//	pal.colors[4].color = 0xFF6138;
	pal.colors[0].color = C1;
	pal.colors[1].color = C2;
	pal.colors[2].color = C3;
	pal.colors[3].color = C4;
	pal.colors[4].color = C5;
	pal.set = GREEN;
	return (pal);
}

t_palette	set_2(void)
{
	t_palette	pal;

	pal.colors[0].color = 0x476C5E;
	pal.colors[1].color = 0xCEF09D;
	pal.colors[2].color = 0xB1E001;
	pal.colors[3].color = 0x083643;
	pal.colors[4].color = 0xB8ECD7;
	pal.set = YELLOW;
	return (pal);
}

t_palette	set_3(void)
{
	t_palette	pal;

//	pal.colors[0].color = 0x2A4858;
//	pal.colors[1].color = 0x007882;
//	pal.colors[2].color = 0x23AA8f;
//	pal.colors[3].color = 0x86D780;
//	pal.colors[4].color = 0xFAFA6E;
	pal.colors[0].color = C5;
	pal.colors[1].color = C4;
	pal.colors[2].color = C3;
	pal.colors[3].color = C2;
	pal.colors[4].color = C1;
	pal.set = BLUE;
	return (pal);
}

t_palette	set_4(void)
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

t_palette	set_5(void)
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

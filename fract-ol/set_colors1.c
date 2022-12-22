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

#define C1	0x88F7E2
#define C2	0x44D492
#define C3	0xF5EB67
#define C4	0xFFA15C
#define C5	0xFA233E

//#define C1	0x88F7E2
//#define C2	0x44D492
//#define C3	0xF5EB67
//#define C4	0xFFA15C
//#define C5	0xFA233E

//#define C1	0x0540F2
//#define C2	0x056CF2
//#define C3	0x0597F2
//#define C4	0x05C7F2
//#define C5	0x05F2DB

//
//#define C1	0xFF9B71
//#define C2	0xFF6549
//#define C3	0xFFA755
//#define C4	0xE8CB9A
//#define C5	0xFFE9AA

//#define C1	0x023B47
//#define C2	0x295E52
//#define C3	0xF2E085
//#define C4	0xFCAB55
//#define C5	0xEE7F38

//#define C1	0x596273
//#define C2	0xF2F0CE
//#define C3	0xF2EC9B
//#define C4	0xF2D750
//#define C5	0xF2AE2E

//#define C1	0x468966
//#define C2	0xFFF0A5
//#define C3	0xFFB03B
//#define C4	0xB64926
//#define C5	0x8E2800

//#define C1	0x0A7B83
//#define C2	0x2AA876
//#define C3	0xFFD265
//#define C4	0xF19C65
//#define C5	0xCE4D45

//#define C1	0x5C4B51
//#define C2	0x8CBEB2
//#define C3	0xF2EBBF
//#define C4	0xF3B562
//#define C5	0xF06060

//#define C1	0xEFC164
//#define C2	0xF3835D
//#define C3	0xF35955
//#define C4	0x286275
//#define C5	0x00434C

//#define C1	0x2C3E50
//#define C2	0xF49D1E
//#define C3	0x1BB89A
//#define C4	0x27A28A
//#define C5	0xFFFFFF

//#define C1	0x4C6472
//#define C2	0x57A4B1
//#define C3	0xB0D894
//#define C4	0xFADE89
//#define C5	0xF95355

//#define C1	0x23254C
//#define C2	0xB6696A
//#define C3	0xE8ECF4
//#define C4	0xE1E2E5
//#define C5	0xE7CE8C

//#define C1	0xEFC164
//#define C2	0xF3835D
//#define C3	0xF35955
//#define C4	0x286275
//#define C5	0x00434C

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

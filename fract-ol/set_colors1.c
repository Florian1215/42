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

#define C1	0x7DBEA5
#define C2	0xF1E0B1
#define C3	0xEE9D31
#define C4	0xF26C1A
#define C5	0x5A392B

t_palette	set_1(int dark_mode)
{
	t_palette	pal;

	(void)dark_mode;
//	pal.colors[0].color = dark_mode ? FG : 0x468966;
//	pal.colors[1].color = dark_mode ? 0x295E52 : 0xFFF0A5;
//	pal.colors[2].color = 0xFFB03B;
//	pal.colors[3].color = 0xB64926;
//	pal.colors[4].color = 0x8E2800;
	pal.colors[4].color = C1;
	pal.colors[3].color = C2;
	pal.colors[2].color = C3;
	pal.colors[1].color = C4;
	pal.colors[0].color = C5;
	pal.set = GREEN;
	return (pal);
}

t_palette	set_2(int dark_mode)
{
	t_palette	pal;

	(void)dark_mode;
	pal.colors[0].color = 0x23254C;
	pal.colors[1].color = 0xB6696A;
	pal.colors[2].color = 0xE8ECF4;
	pal.colors[3].color = 0xE1E2E5;
	pal.colors[4].color = 0xE7CE8C;
	pal.set = PURPLE;
	return (pal);
}

t_palette	set_3(int dark_mode)
{
	t_palette	pal;

	(void)dark_mode;
//	pal.colors[0].color = 0x2A4858;
//	pal.colors[1].color = 0x007882;
//	pal.colors[2].color = 0x23AA8f;
//	pal.colors[3].color = 0x86D780;
//	pal.colors[4].color = 0xFAFA6E;
	pal.colors[4].color = C5;
	pal.colors[3].color = C4;
	pal.colors[2].color = C3;
	pal.colors[1].color = C2;
	pal.colors[0].color = C1;
	pal.set = BLUE;
	return (pal);
}

t_palette	set_4(int dark_mode)
{
	t_palette	pal;

	(void)dark_mode;
		// REVERSE !!
	pal.colors[4].color = 0x4C6472;
	pal.colors[3].color = 0x57A4B1;
	pal.colors[2].color = 0xB0D894;
	pal.colors[1].color = 0xFADE89;
	pal.colors[0].color = 0xF95355;
	pal.set = RED;
	return (pal);
}

t_palette	set_5(int dark_mode)
{
	t_palette	pal;

	printf("set 5\n");
	(void)dark_mode;
	pal.colors[0].color = 0xA1DBB2;
	pal.colors[1].color = 0xFEE5AD;
	pal.colors[2].color = 0xFACA66;
	pal.colors[3].color = 0xF7A541;
	pal.colors[4].color = 0xF45D4C;
	pal.set = GREY;
	return (pal);
}

// LIGHT_GREEN_ORANGE 4/5
//
//
//
//
//

// DARK_GREEN 1/5
//0x051E21
//0x00302D
//0x856434
//0xF28C28
//0xFFAD4E

// BLUE_WHITe 2/5
//0x003354
//0x91BED4
//0xD9E8F5
//0xFFFFFF
//0xF26101

// DARK_MODE_PERFECT RED 5/5
//0xDC3522
//0xD9CB9E
//0x374140
//0x2A2C2B
//0x1E1E20

// LIGHT_BLUE
//0xfadda2
//0x6b61ff
//0x66a1ff
//0x8ecde6
//0xf0eff4

// GREEN 2/5
//0x476C5E
//0xCEF09D
//0xB1E001
//0x083643
//0xB8ECD7

// DARK_BLUE 2/5
//0x0B2631
//0x18445D
//0x1F7799
//0x04C4D9
//0x79E6F2

// BLUE 2/5
//0x004056
//0x2C858D
//0x74CEB7
//0xC9FFD5
//0xFFFFCB

// PASTEL_BLUE
//0x577BAC
//0x7EA1BF
//0x9FB0BF
//0xC7D1D9
//0xEBEFF2

// PINK 4/5
//0x441122
//0xCC4466
//0xFF99AA
//0xFFCCCC
//0xEE7788

// DARK_GREY
//FG
//0x263248
//0x7E8AA2
//0xFFFFFF
//0xFF9800

// PASTEL BLUE
//0x63A69F
//0xF2E1AC
//0xF2836B
//0xF2594B
//0xCD2C24

// PINK
//0x282d3c
//0x5b5d70
//0x74838c
//0xffc4b8
//0xf69197

// PASTEL_PINK
//0xfda9a9
//0xf3eded
//0xb9eedc
//0x96beb1
//0x82939b

// PINK
//0xfbbbad
//0xee8695
//0x4a7a96
//0x333f58
//0x292831
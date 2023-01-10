/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_edou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:37:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/09 14:37:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	int	res;

	i = 7;
	while (i >= 0)
	{
		res = (octet >> i & 1) + '0';
		write(1, &res, 1);
		i--;
	}
}

int	main(void)
{
	print_bits(58);
}

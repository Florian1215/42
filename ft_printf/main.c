/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:11:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/03 15:11:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		format;

	line = "\\\\!/%0#44x\\\\!/";
	format = -2044674958;
	printf("| %d\n", printf(line, format));
	printf("| %d\n", ft_printf(line, format));
}



//>------------<                                0x2bff4f47>------------<| 70
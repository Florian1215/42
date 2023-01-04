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
	char	*format;

	line = "%-7.5s";
	format = "yolo";
	printf("| %d\n", printf(line, format));
	printf("| %d\n", ft_printf(line, format));
}

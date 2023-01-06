/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:22:33 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/02 18:22:35 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	printf("\nA (%d) - B (%d) | sort %d\n", stack->len_a, stack->len_b, is_sort(stack, 1));
	while (i < stack->len_a || i < stack->len_b)
	{
		if (i < stack->len_a)
			printf("%d\t", stack->a[i]);
		else
			printf(".\t");
		if (i < stack->len_b)
			printf("%d", stack->b[i]);
		else
			printf(".");
		printf("\n");
		i++;
	}
	printf("\n");
}

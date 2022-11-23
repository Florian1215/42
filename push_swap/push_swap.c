/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:52:20 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/23 15:19:53 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(char letter, int *stack, int len)
{
	printf("Stack = %c [ ", letter);
	for (int i = 0; i <  len; i++)
		printf("%d, ", stack[i]);
	printf(" ]\n");
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack = parsing(--ac, ++av);
	print_stack('a', stack.a, stack.len_a);
	print_stack('b', stack.b, stack.len_b);
	printf("PUSH\n");
	push_b(&stack);
	print_stack('a', stack.a, stack.len_a);
	print_stack('b', stack.b, stack.len_b);
}

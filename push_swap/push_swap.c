/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:52:20 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/27 11:55:41 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack stack)
{
	int	i;

	i = 0;
	printf("\nA (%d) - B (%d)\n", stack.len_a, stack.len_b);
	while (i < stack.len_a || i < stack.len_b)
	{
		if (i < stack.len_a)
			printf("%d\t", stack.a[i]);
		else
			printf(".\t");
		if (i < stack.len_b)
			printf("%d", stack.b[i]);
		else
			printf(".");
		printf("\n");
		i++;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack = parsing(--ac, ++av);
	if (!is_sort(stack))
	{
		if (stack.len > 5)
			solve(&stack, 0);
		else
			solve_selection_sort(&stack);
	}
	free_stack(stack);
}

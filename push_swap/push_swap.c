/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:52:20 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/02 18:24:13 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 1)
		return (0);
	stack = parsing(--ac, ++av);
	if (stack)
	{
		if (!is_sort(stack, 0))
		{
			if (stack->len == 3)
				solve3(stack);
			else if (stack->len == 5)
				solve5(stack);
			else if (stack->len < 20)
				solve_selection_sort(stack);
			else
				solve(stack, 0);
		}
		free_stack(stack, 1, 1);
	}
}

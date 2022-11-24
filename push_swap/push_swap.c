/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:52:20 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/24 12:33:54 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_nl(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	free_stack(t_stack stack)
{
	free(stack.a);
	free(stack.b);
}

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

	printf("%d\n", ac);
	stack = parsing(--ac, ++av);
	solve(&stack);
	//print_stack(stack);
	free_stack(stack);
}

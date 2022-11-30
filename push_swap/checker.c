/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:33:01 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/29 19:11:31 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	printf("\nA (%d) - B (%d)\n", stack->len_a, stack->len_b);
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

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	instructions(char *ins, t_stack *stack)
{
	if (!ft_strcmp(ins, "sa"))
		swap_a(stack, 0);
	else if (!ft_strcmp(ins, "sb"))
		swap_b(stack, 0);
	else if (!ft_strcmp(ins, "ss"))
		swap_ab(stack, 0);
	else if (!ft_strcmp(ins, "pa"))
		push_a(stack, 0);
	else if (!ft_strcmp(ins, "pb"))
		push_b(stack, 0);
	else if (!ft_strcmp(ins, "ra"))
		rotate_a(stack, 0);
	else if (!ft_strcmp(ins, "rb"))
		rotate_b(stack, 0);
	else if (!ft_strcmp(ins, "rr"))
		rotate_ab(stack, 0);
	else if (!ft_strcmp(ins, "rra"))
		reverse_a(stack, 0);
	else if (!ft_strcmp(ins, "rrb"))
		reverse_b(stack, 0);
	else if (!ft_strcmp(ins, "rrr"))
		reverse_ab(stack, 0);
	else
		error_(stack);
	//print_stack(stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	char	*line;

	if (ac == 1)
		return (0);
	stack = parsing(--ac, ++av);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		instructions(line, stack);
		free(line);
	}
	if (is_sort(stack))
		ft_putstr_nl("OK");
	else
		ft_putstr_nl("KO");
	free_stack(stack, 0, 0);
}

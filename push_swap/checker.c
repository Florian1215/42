/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:33:01 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/28 17:16:48 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		swap_a(stack);
	else if (!ft_strcmp(ins, "sb"))
		swap_b(stack);
	else if (!ft_strcmp(ins, "ss"))
		swap_ab(stack);
	else if (!ft_strcmp(ins, "pa"))
		push_a(stack);
	else if (!ft_strcmp(ins, "pb"))
		push_b(stack);
	else if (!ft_strcmp(ins, "ra"))
		rotate_a(stack);
	else if (!ft_strcmp(ins, "rb"))
		rotate_b(stack);
	else if (!ft_strcmp(ins, "rr"))
		rotate_ab(stack);
	else if (!ft_strcmp(ins, "rra"))
		reverse_a(stack);
	else if (!ft_strcmp(ins, "rrb"))
		reverse_b(stack);
	else if (!ft_strcmp(ins, "rrr"))
		reverse_ab(stack);
	else
		error_(stack);
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
	free_stack(stack, 1, 1);
}

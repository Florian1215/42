/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:33:01 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/27 14:33:04 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_cmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	instructions(char *line, t_stack *stack)
{
	if (!str_cmp(line, "sa"))
		sa(stack);
	else if (!str_cmp(line, "sb"))
		sb(stack);
	else if (!str_cmp(line, "ss"))
		ss(stack);
	else if (!str_cmp(line, "pa"))
		pa(stack);
	else if (!str_cmp(line, "pb"))
		pb(stack);
	else if (!str_cmp(line, "ra"))
		ra(stack);
	else if (!str_cmp(line, "rb"))
		rb(stack);
	else if (!str_cmp(line, "rr"))
		rr(stack);
	else if (!str_cmp(line, "rra"))
		rra(stack);
	else if (!str_cmp(line, "rrb"))
		rrb(stack);
	else if (!str_cmp(line, "rrr"))
		rrr(stack);
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
	if (!stack)
		return (1);
	stack->print = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		instructions(line, stack);
		free(line);
	}
	if (is_sort(stack, 1))
		put_str_nl("\033[92mOK\033[0m");
	else
		put_str_nl("\033[91mKO\033[0m");
	free_stack(stack, ALL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:57:57 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/27 09:10:52 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_atoi(char *nb, int i, t_stack *stack)
{
	long unsigned int	res;
	int					sign;
	int					j;

	sign = 1;
	res = 0;
	j = 0;
	if (nb[j] == '-')
	{
		sign = -sign;
		j++;
	}
	while (nb[j] >= '0' && nb[j] <= '9')
		res = res * 10 + nb[j++] - '0';
	if (!j || (j == 1 && sign == -1) || res - (sign < 0) > INT_MAX)
		return (error_(*stack));
	stack->a[i] = (int)res * sign;
	j = 0;
	while (j < i)
		if (stack->a[j++] == stack->a[i])
			return (error_(*stack));
}

t_stack	parsing(int ac, char **av)
{
	t_stack	stack;
	int		i;

	stack.a = malloc(ac * sizeof(int));
	stack.b = malloc(ac * sizeof(int));
	if (!ac)
	{
		error_(stack);
		return (stack);
	}
	stack.len = ac;
	stack.len_a = ac;
	stack.len_b = 0;
	i = -1;
	while (++i < ac)
		ft_atoi(av[i], i, &stack);
	return (stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:57:57 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/23 11:10:24 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parsing_error(t_stack stack)
{
	free(stack.a);
	free(stack.b);
	ft_putstr_nl("Error");
	exit(-1);
}

static void	ft_atoi(char *nb, int i, t_stack *stack)
{
	long long unsigned int	res;
	int						sign;
	int						j;

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
	if (!j || (j == 1 && sign == -1) || res - (sign < 0) > INT32_MAX)
		return (parsing_error(*stack));
	(*stack).a[i] = (int)res * sign;
	j = 0;
	while (j < i)
		if ((*stack).a[j++] == (*stack).a[i])
			return (parsing_error(*stack));
}

t_stack	parsing(int ac, char **av)
{
	t_stack	stack;
	int		i;

	stack.a = malloc(ac * sizeof(int));
	stack.b = malloc(ac * sizeof(int));
	if (!ac)
	{
		parsing_error(stack);
		return (stack);
	}
	stack.len = ac;
	i = -1;
	while (++i < ac)
		ft_atoi(av[i], i, &stack);
	return (stack);
}

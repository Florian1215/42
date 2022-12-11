/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:57:57 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/03 14:52:48 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_atoi(char *nb, int j, t_stack *stack)
{
	long unsigned int	res;
	int					sign;
	int					i;

	sign = 1;
	res = 0;
	if (nb[0] == '-')
		sign = -sign;
	i = sign == -1;
	while (nb[i] >= '0' && nb[i] <= '9')
		res = res * 10 + nb[i++] - '0';
	if (!i || (i == 1 && sign == -1) || ft_strlen(nb) != i)
		return (error_(stack));
	if (res - (sign < 0) > INT_MAX)
		return (error_(stack));
	stack->a[j] = (int)res * sign;
	i = 0;
	while (i < j)
		if (stack->a[i++] == stack->a[j])
			return (error_(stack));
}

static t_stack	*malloc_pasring(int ac, char **av)
{
	t_stack	*stack;
	int		i;
	int		ct;

	i = -1;
	ct = 0;
	while (++i < ac)
		ct += ft_countword(av[i]);
	if (!ct)
		return (error_(NULL), NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = malloc(ct * sizeof(int));
	if (!stack->a)
		return (free_stack(stack, 0, 0));
	stack->b = malloc(ct * sizeof(int));
	if (!stack->b)
		return (free_stack(stack, 1, 0));
	stack->len = ct;
	stack->len_a = ct;
	stack->len_b = 0;
	return (stack);
}

t_stack	*parsing(int ac, char **av)
{
	t_stack	*stack;
	int		i;
	int		j;
	int		k;
	char	**split;

	stack = malloc_pasring(ac, av);
	if (!stack)
		return (NULL);
	i = 0;
	k = 0;
	while (i < ac)
	{
		j = 0;
		split = ft_split(av[i++]);
		while (split[j])
			ft_atoi(split[j++], k++, stack);
		ft_free_split(split, -1);
	}
	get_index(stack);
	return (stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:32:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/26 15:32:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_a_location_min(t_stack *stack)
{
	int			ret;
	int			index;
	int			tmp;
	int			i;

	ret = 0;
	i = 0;
	index = get_min(stack);
	while (i < stack->len_a)
	{
		tmp = stack->a[i];
		if (tmp == index)
			break ;
		ret++;
		i++;
	}
	if (ret >= (stack->len_a + 1) / 2)
		ret = (stack->len_a - ret) * -1;
	return (ret);
}

int	set_a_location_max(t_stack *stack)
{
	int			ret;
	int			index;
	int			tmp;
	int			i;

	ret = 0;
	tmp = 0;
	i = 0;
	index = get_max(stack);
	while (i < stack->len_a)
	{
		tmp = stack->a[i];
		if (tmp == index)
			break ;
		ret++;
		i++;
	}
	ret++;
	if (ret >= (stack->len_a + 1) / 2)
		ret = (stack->len_a - ret) * -1;
	return (ret);
}

int	set_a_location_mid(int num, t_stack *stack)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (i + 1 < stack->len_a)
	{
		if (num > stack->a[i] && num < stack->a[i + 1])
			break ;
		ret++;
		i++;
	}
	if (ret >= (stack->len_a + 1) / 2)
		ret = (stack->len_a - ret) * -1;
	return (ret);
}

int	set_a_location(int num, t_stack *stack)
{
	int	ret;

	if (num < get_min(stack))
		ret = set_a_location_min(stack);
	else if (num > get_max(stack))
		ret = set_a_location_max(stack);
	else
		ret = set_a_location_mid(num, stack);
	return (ret);
}

int	ft_get_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	get_min_rotate(t_stack *stack, int *a, int *b)
{
	int			a_location;
	int			b_location;
	int			index;
	int			num;
	int 		i;

	index = 0;
	i = 0;
	while (index < stack->len_b)
	{
		num = stack->b[i];
		a_location = set_a_location(num, stack);
		if (index >= (stack->len_b + 1) / 2)
			b_location = (stack->len_b - index) * -1;
		else
			b_location = index;
		if (index == 0 || ft_get_bigger(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		i++;
		index++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:39:34 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/06 14:18:28 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define CHUNCK1 4 //  0  1  2  3  4
#define CHUNCK2 9 //  5  6  7  8  9
#define CHUNCK3 14// 10 11 12 13 14
#define CHUNCK4 19// 15 16 17 18 19

void	rotate_or_reverse(t_stack *stack, int n, enum e_stacks s)
{
	static void	(*rotate[2])() = {rotate_a, rotate_b};
	static void	(*reverse[2])() = {reverse_a, reverse_b};
	int			len;

	if (s == A)
		len = stack->len_a;
	else
		len = stack->len_b;
	if (n > (len + 1) / 2)
		reverse[s](stack, 1);
	else
		rotate[s](stack, 1);
}

void	smallest_b(t_stack *stack)
{
	int	i;

	if (!stack->len_b)
		return ;
	i = -1;
	while (++i)
		if (stack->a[0] < stack->b[i])
			break ;
	while (stack->a[0] < stack->b[0])
		rotate_or_reverse(stack, i, B);
}

void	solve20(t_stack *stack)
{
	int	hold_first;
	int	hold_second;
	int	i;

	if (is_sort(stack, 1) || stack->chunck * stack->chunck_size > stack->len)
		return ;
	hold_first = 0;
	while (hold_first < stack->len_a)
	{
		if (stack->a[hold_first] <= stack->chunck * stack->chunck_size)
			break ;
		hold_first++;
	}
	hold_second = stack->len_a - 1;
	while (hold_second >= 0)
	{
		if (stack->a[hold_second] <= stack->chunck * stack->chunck_size)
			break ;
		hold_second--;
	}
	hold_second = stack->len_a - hold_second;
	i = -1;
	if (hold_first < hold_second)
		while (++i < hold_first)
			rotate_or_reverse(stack, hold_first, A);
	else
		while (++i < hold_second)
			rotate_or_reverse(stack, stack->len_a - hold_second, A);
	smallest_b(stack);
	push_b(stack, 1);
	if (stack->len_b == stack->chunck * stack->chunck_size)
		stack->chunck++;
	//printf("first = %d - second = %d - chunk %d\n", hold_first, hold_second, stack->chunck * stack->chunck_size);
	//print_stack(stack);
	solve20(stack);
}

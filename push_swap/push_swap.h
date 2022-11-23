/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:52:50 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/23 14:38:28 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
//# include <sys/uio.h>
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // delete !!!

typedef struct s_stack
{
	int	*a;
	int	len_a;
	int	*b;
	int	len_b;
	int	len;
}				t_stack;

t_stack	parsing(int ac, char **av);
void	ft_putstr_nl(char *str);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack);

void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

void	rotate_ab(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);

void	reverse_ab(t_stack *stack);
void	reverse_a(t_stack *stack);
void	reverse_b(t_stack *stack);

void    move_up(int *stack, int *len);
void    move_down(int *stack, int *len);

#endif
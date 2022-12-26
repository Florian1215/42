/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:52:50 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/06 14:18:34 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack		t_stack;
typedef enum e_free_stacks	t_free_stacks;

struct s_stack
{
	int	*a;
	int	len_a;
	int	*b;
	int	len_b;
	int	len;
	int	print;
};

enum e_free_stacks
{
	NONE,
	A,
	ALL,
};

// GNL
char	*get_next_line(int fd);

// SOLVE
void	solve3(t_stack *stack);
void	solve5(t_stack *stack);
void	solve(t_stack *stack);
void	solve_b(t_stack *stack);

void	efficient_rr(t_stack *stack, int *a, int *b);
void	efficient_ra(t_stack *stack, int a);
void	efficient_rb(t_stack *stack, int b);
int		get_min(t_stack *stack);
int	get_min_index(t_stack *stack);
int		get_max(t_stack *stack);

void	get_min_rotate(t_stack *stack, int *a, int *b);
int		set_a_location_min(t_stack *stack);

// UTILS
void	error_(t_stack *stack);
t_stack	*parsing(int ac, char **av);
void	*free_stack(t_stack *stack, t_free_stacks stacks);
void	put_str_nl(char *str);
int		is_sort(t_stack *stack, int check_b);
int		*convert_to_index(t_stack *stack);
void	get_index(t_stack *stack);
int		str_len(char *str);
char	**split_(char const *s);
char	**free_split(char **split, int i);
int		ct_word(char const *s);

// INSTRUCTIONS
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack);

void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_ab(t_stack *stack);

void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_ab(t_stack *stack);

void	move_up(int *stack, int *len);
void	move_down(int *stack, int *len);

# include <stdio.h>
void	print_stack(t_stack *stack);

#endif
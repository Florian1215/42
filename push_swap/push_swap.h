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
typedef enum e_stacks		t_stacks;

struct s_stack
{
	int	*a;
	int	len_a;
	int	*b;
	int	len_b;
	int	len;
	int	print;
};

enum e_stacks
{
	NONE,
	A,
	B = 0,
	ALL,
};

// SOLVE
void	efficient_move(t_stack *stack, t_stacks s, int index);
void	efficient_rr(t_stack *stack, int *a, int *b);
int		get_side(int i, int len);
int		get_min(t_stack *stack);
int		get_min_index(t_stack *stack);
void	get_min_rotate(t_stack *stack, int *a, int *b);
int		get_max(t_stack *stack);
int		get_max_index(t_stack *stack);

// UTILS
char	*get_next_line(int fd);
void	error_(t_stack *stack);
t_stack	*parsing(int ac, char **av);
void	*free_stack(t_stack *stack, t_stacks stacks);
void	put_str_nl(char *str);
int		is_sort(t_stack *stack, int check_b);
int		*convert_to_index(t_stack *stack);
void	get_index(t_stack *stack);
int		str_len(char *str);
char	**split_(char const *s);
char	**free_split(char **split, int i);
int		ct_word(char const *s);

// INSTRUCTIONS
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

void	move_up(int *stack, int *len);
void	move_down(int *stack, int *len);

#endif
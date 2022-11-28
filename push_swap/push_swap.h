/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:52:50 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/28 17:21:13 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*a;
	int	len_a;
	int	*b;
	int	len_b;
	int	len;
}				t_stack;

// GNL
typedef struct s_list
{
	char			*buff;
	struct s_list	*next;
}				t_list;

# define BUFFER_SIZE 20

char	*get_next_line(int fd);
void	ft_lstrm_first(t_list **lst);
t_list	*ft_lstnew(char *buff);
void	ft_lstadd_back(t_list **lst, t_list *new_lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_find_nl(t_list *lst, int one_lst);

// SOLVE
void	solve(t_stack *stack, int index);
void	solve_selection_sort(t_stack *stack);

// UTILS
void	error_(t_stack *stack);
t_stack	*parsing(int ac, char **av);
void	*free_stack(t_stack *stack, int free_a, int free_b);
void	ft_putstr_nl(char *str);
int		is_sort(t_stack *stack);
int		to_binary(int nb);
int		*convert_to_index(t_stack *stack);
void	get_index(t_stack *stack);
int		ft_strlen(char *str);
char	**ft_split(char const *s);
int		ft_countword(char const *s);

// INSTRUCTIONS
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack);

void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_ab(t_stack *stack);

void	reverse_a(t_stack *stack);
void	reverse_b(t_stack *stack);
void	reverse_ab(t_stack *stack);

void	move_up(int *stack, int *len);
void	move_down(int *stack, int *len);

// PRINT 
# include <stdio.h>
//void	print_stack(t_stack *stack);

#endif
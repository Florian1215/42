
#include "push_swap.h"

static void    rotate(int *stack, int *len)
{
    int tmp;

    if (*len <= 1)
        return ;
    tmp = stack[0];
    move_up(stack, len);
    stack[*len] = tmp;
    *len += 1;
}

void    rotate_a(t_stack *stack)
{
    rotate(stack->a, &stack->len_a);
	ft_putstr_nl("ra");
}

void    rotate_b(t_stack *stack)
{
    rotate(stack->b, &stack->len_b);
	ft_putstr_nl("rb");
}

void    rotate_ab(t_stack *stack)
{
    rotate_a(stack);
	rotate_b(stack);
}

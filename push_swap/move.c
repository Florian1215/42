
void    move_up(int *stack, int *len)
{
    int i;

    i = -1;
	*len -= 1;
    while (++i < *len)
		stack[i] = stack[i + 1];
}

void    move_down(int *stack, int *len)
{
    int i;

    i = 0;
	while (++i <= *len)
		stack[*len - i + 1] = stack[*len - i];
    *len += 1;
}

static int	error_(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	return (-1);
}

int	check_args(int ac, char **av)
{
	char	*binary_path;
	int		i;

	if (ac != 4)
		return (error_("Wrong number of arguments"));
	if (access(av[0], F_OK) == -1)
		return (error_("No such file"));
	if (access(av[0], R_OK) == -1 || \
		(!access(av[3], F_OK) && access(av[3], W_OK) == -1))
		return (error_("Files don't have right access"));
	i = 0;
	while (++i < 3)
	{
		binary_path = get_binary(ft_split(av[i]), 1);
		if (!binary_path)
			return (error_("The binary of the command doesn't exist"));
		free(binary_path);
	}
	return (0);
}

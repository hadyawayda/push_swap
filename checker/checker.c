#include "../src/utils/headers/push_swap.h"

void	check_sub(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		rra(a);
	else if (line[2] == 'b')
		rrb(b);
	else if (line[2] == 'r')
		rrr(a, b);
}

char	*check(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b);
	else
		ft_error_ch();
	return (get_next_line(0));
}

void	checker_sub(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!checksorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char	*line;

	b = NULL;
	a = process(argc, argv);
	if (!a || checkdup(a))
	{
		ft_free (&a);
		ft_error_ch();
	}
	line = get_next_line(0);
	if (!line && !checksorted(a))
		write(1, "KO\n", 3);
	else if (!line && checksorted(a))
		write(1, "OK\n", 3);
	else
		checker_sub(&a, &b, line);
	ft_free(&b);
	ft_free(&a);
	return (0);
}

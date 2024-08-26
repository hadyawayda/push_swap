/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 03:19:50 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/26 03:19:51 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void	check_sub(t_stack_node **a, t_stack_node **b, char *line)
{
	if (line[2] == 'a')
		rra(a);
	else if (line[2] == 'b')
		rrb(b);
	else if (line[2] == 'r')
		rrr(a, b);
}

char	*check(t_stack_node **a, t_stack_node **b, char *line)
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

void	checker_sub(t_stack_node **a, t_stack_node **b, char *line)
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

t_stack_node	*ft_sub_process(char **argv)
{
	t_stack_node	*a;
	char			**tmp;
	int				i;
	int				j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = atoi_modified(tmp[i]);
		stack_add_back(&a, stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack_node	*ft_process(int argc, char **argv)
{
	t_stack_node	*a;
	int				i;
	int				j;

	i = 1;
	a = NULL;
	if (argc < 2)
		error();
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = atoi_modified(argv[i]);
			stack_add_back(&a, stack_new(j));
			i++;
		}
	}
	return (a);
}

void	print_stack(t_stack_node *a)
{
	while (a)
	{
		printf("%d ", a->value);
		a = a->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;

	b = NULL;
	printf("checker started\n");
	a = ft_process(argc, argv);
	if (!a || checkdup(a))
	{
		ft_free(&a);
		ft_error_ch();
	}
	print_stack(a);
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

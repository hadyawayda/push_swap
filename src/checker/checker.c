/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 03:19:50 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/26 23:42:15 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void	ft_error_ch(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	execute_command(t_stack_node **a, t_stack_node **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_m(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_m(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		swap_both(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_m(b, a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_m(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_m(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_m(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate_m(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate_m(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		reverse_rotate_both(a, b);
	else
		ft_error_ch();
}

void	extract_lines(t_stack_node **a, t_stack_node **b, char *line)
{
	while (line)
	{
		execute_command(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (*b || !checksorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

t_stack_node	*process_checker(int argc, char **argv)
{
	t_stack_node	*a;
	char			*combined_args;
	char			**list;
	int				i;

	a = NULL;
	combined_args = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		combined_args = ft_strjoin_and_free(combined_args, argv[i++]);
		combined_args = ft_strjoin_and_free(combined_args, " ");
	}
	list = ft_split(combined_args, ' ');
	free(combined_args);
	i = 0;
	while (list[i])
		stack_add_back(&a, stack_new(atoi_modified(list[i++])));
	ft_freestr(list);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;

	if (argc < 2)
		return (0);
	b = NULL;
	a = process_checker(argc, argv);
	if (!a || checkdup(a))
	{
		ft_free(&a);
		ft_error_ch();
	}
	line = get_next_line(0);
	extract_lines(&a, &b, line);
	ft_free(&b);
	ft_free(&a);
	return (0);
}

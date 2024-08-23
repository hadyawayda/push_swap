/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 03:22:30 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/21 03:22:31 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

bool	is_valid_number(char *str)
{
	long long	num;
	int			j;
	int			sign;

	num = 0;
	j = 0;
	sign = 1;
	if (str[0] == '-')
	{
		j = 1;
		sign = -1;
	}
	if (str[j] == '\0')
		return (false);
	while (str[j] != '\0')
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
			return (false);
		num = num * 10 + (str[j] - '0');
		if ((sign * num) < INT_MIN || (sign * num) > INT_MAX)
			return (false);
		j++;
	}
	return (true);
}

bool	is_numeric(char **arg, int i)
{
	while (arg[i] != NULL)
	{
		if (!is_valid_number(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

void	process(t_stack_node **a, char **list, int i)
{
	int				value;

	if (!is_numeric(list, i))
	{
		write(2, "Error\n", 6);
		return ;
	}
	while (list[i])
	{
		value = atoi_modified(list[i]);
		stack_add_back(a, stack_new(value));
		i++;
	}
}

void	subprocess(t_stack_node **a, char **argv)
{
	char			**list;

	list = ft_split(argv[1], ' ');
	process(a, list, 0);
	ft_freestr(list);
}

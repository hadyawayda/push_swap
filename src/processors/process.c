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
	int	value;

	if (!is_numeric(list, i))
		return ;
	while (list[i])
	{
		value = atoi_modified(list[i]);
		stack_add_back(a, stack_new(value));
		i++;
	}
}

void	subprocess(t_stack_node **a, char **argv)
{
	char	**list;

	list = ft_split_charset(argv[1], " \n\t\v\f\r");
	process(a, list, 0);
	ft_freestr(list);
}

void	multi_arg_process(t_stack_node **a, char **argv)
{
	char	*combined_args;
	char	**list;
	int		i;
	char	*tmp;

	combined_args = ft_strjoin(argv[1], " ");
	i = 2;
	while (argv[i])
	{
		tmp = combined_args;
		combined_args = ft_strjoin(combined_args, argv[i]);
		free(tmp);
		tmp = combined_args;
		combined_args = ft_strjoin(combined_args, " ");
		free(tmp);
		i++;
	}
	list = ft_split_charset(combined_args, " \n\t\v\f\r");
	free(combined_args);
	process(a, list, 0);
	ft_freestr(list);
}

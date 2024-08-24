/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:38:39 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/19 00:38:41 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/headers/push_swap.h"

int counter = 0;

int	main(int argc, char **argv)
{
	t_stack_node	*a;

	a = pre_process(argc, argv);
	if (!a || checkdup(a))
	{
		ft_free(&a);
		error();
	}
	if (!checksorted(a))
		sort(&a);
	ft_free(&a);
	return (0);
}

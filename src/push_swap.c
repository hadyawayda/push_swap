/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:59:31 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/27 02:59:32 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/headers/push_swap.h"

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

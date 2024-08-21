/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:58:17 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/20 03:58:18 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

t_stack_node	*pre_process(int argc, char **argv)
{
	t_stack_node	*a;

	a = NULL;
	if (argc < 2)
		error();
	if (argc == 2)
		subprocess(&a, argv);
	else
		process(&a, argv, 1);
	return (a);
}

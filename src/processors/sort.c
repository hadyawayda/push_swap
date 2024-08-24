/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:17:19 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/23 01:17:20 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void	print_stack(t_stack_node *a)
{
	while (a)
	{
		printf("%d ", a->value);
		a = a->next;
	}
	printf("\n");
}

void	sort(t_stack_node **a)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two_stack(a);
	else if (size == 3)
		sort_three_stack(a);
	else
		sort_large_stack(a);
	print_stack(*a);
}

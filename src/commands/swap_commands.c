/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:22:17 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/20 02:22:18 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void	sa(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	tmp = *a;
	tmp2 = *a;
	while (tmp)
	{
		if (tmp->next)
			tmp2 = tmp->next;
		tmp = tmp->next;
	}
	tmp = *a;
	*a = tmp->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	tmp = *b;
	tmp2 = *b;
	while (tmp)
	{
		if (tmp->next)
			tmp2 = tmp->next;
		tmp = tmp->next;
	}
	tmp = *b;
	*b = tmp->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:22:09 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/20 02:22:10 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void	ra(t_stack_node **a)
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
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
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
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

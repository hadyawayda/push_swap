/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:23:52 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/23 04:23:53 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	calculate_cost_to_top(t_stack_node *a, t_stack_node *target)
{
	int				cost;
	t_stack_node	*current;

	cost = 0;
	current = a;
	while (current != target)
	{
		current = current->next;
		cost++;
	}
	if (cost > stack_size(a) / 2)
		cost = stack_size(a) - cost;
	return (cost);
}

void	calculate_cheapest(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*current_node;
	int				min_cost;
	int				current_cost;

	current_node = *a;
	cheapest_node = NULL;
	min_cost = INT_MAX;
	while (current_node)
	{
		current_cost = calculate_cost_to_top(*a, current_node);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest_node = current_node;
		}
		current_node = current_node->next;
	}
	while (*a != cheapest_node)
	{
		if (calculate_cost_to_top(*a, cheapest_node) <= stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}

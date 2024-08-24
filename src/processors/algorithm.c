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

void rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b, int pos_a, int pos_b, int size_a)
{
    if (pos_a <= stack_size(*stack_a) / 2) {
		for (int i = 0; i < pos_a; i++) ra(stack_a);
	} else {
		for (int i = 0; i < stack_size(*stack_a) - pos_a; i++) rra(stack_a);
	}

	if (pos_b <= stack_size(*stack_b) / 2) {
		for (int i = 0; i < pos_b; i++) rb(stack_b);
	} else {
		for (int i = 0; i < stack_size(*stack_b) - pos_b; i++) rrb(stack_b);
	}
}

void	calculate_best_position(t_stack_node **stack_a, t_stack_node **stack_b, int *best_pos_a, int *best_pos_b, int *min_cost, int size_a)
{
	t_stack_node *current_a = *stack_a;
	for (int i = 0; i < size_a; i++) {
		int pos_b = find_optimal_position(*stack_b, current_a->value);
		int cost = calculate_cost(*stack_a, *stack_b, i, pos_b);

		if (cost < *min_cost) {
			*min_cost = cost;
			*best_pos_a = i;
			*best_pos_b = pos_b;
		}
		current_a = current_a->next;
	}
}

void	calculate_cheapest(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int min_cost = INT_MAX;
	int best_pos_a = 0;
	int best_pos_b = 0;
    int size_a = stack_size(*stack_a);

	calculate_best_position(stack_a, stack_b, &best_pos_a, &best_pos_b, &min_cost, size_a);

	rotate_stacks(stack_a, stack_b, best_pos_a, best_pos_b, size_a);

	pb(stack_a, stack_b);
}

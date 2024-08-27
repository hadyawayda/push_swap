/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:23:52 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/26 06:51:36 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	find_optimal_position(t_stack_node *stack, int value)
{
	t_stack_node	*current;
	int				position;
	int				prev_value;

	if (!stack)
		return (0);
	current = stack;
	position = 0;
	if (value > find_max(stack) || value < find_min(stack))
	{
		while (current && current->value != find_min(stack))
		{
			position++;
			current = current->next;
		}
		return ((position + 1) % stack_size(stack));
	}
	current = stack;
	if (current->next)
		prev_value = current->value;
	else
		prev_value = find_max(stack);
	return (iterate_over_stack_decreasing(&stack, current, value, prev_value));
}

int	calculate_cost(t_stack_node *stack_a, t_stack_node *stack_b, int pos_a,
		int pos_b)
{
	int	size_a;
	int	size_b;
	int	cost_a;
	int	cost_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	if (pos_a <= size_a / 2)
		cost_a = pos_a;
	else
		cost_a = size_a - pos_a;
	if (pos_b <= size_b / 2)
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	if ((pos_a <= size_a / 2 && pos_b <= size_b / 2) || (pos_a > size_a / 2
			&& pos_b > size_b / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else
		return (cost_a + cost_b);
}

void	calculate_best_position(t_stack_node **stack_a, t_stack_node **stack_b,
		int *best_pos_a, int *best_pos_b)
{
	t_stack_node	*current_a;
	int				pos_b;
	int				cost;
	int				i;
	int				min_cost;

	i = 0;
	min_cost = INT_MAX;
	current_a = *stack_a;
	while (i < stack_size(*stack_a))
	{
		pos_b = find_optimal_position(*stack_b, current_a->value);
		cost = calculate_cost(*stack_a, *stack_b, i, pos_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			*best_pos_a = i;
			*best_pos_b = pos_b;
		}
		current_a = current_a->next;
		i++;
	}
}

void	calculate_cheapest(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	best_pos_a;
	int	best_pos_b;

	best_pos_a = 0;
	best_pos_b = 0;
	calculate_best_position(stack_a, stack_b, &best_pos_a, &best_pos_b);
	rotate_stacks(stack_a, stack_b, best_pos_a, best_pos_b);
	pb(stack_a, stack_b);
}

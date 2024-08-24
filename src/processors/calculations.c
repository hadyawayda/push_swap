/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:21:15 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/24 01:21:16 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

int	find_min(t_stack_node *stack)
{
	int min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int find_max(t_stack_node *stack) {
	int max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int find_optimal_position(t_stack_node *stack, int value)
{
	if (!stack) return 0;
	
	t_stack_node *current = stack;
	int position = 0;
	int min = find_min(stack);
	int max = find_max(stack);
	int size = stack_size(stack);
	
	if (value < min || value > max)
	{
		while (current && current->value != max)
		{
			position++;
			current = current->next;
		}
		return ((position + 1) % size);
	}
	current = stack;
	int prev_value = (current->next) ? current->value : min;
	for (int i = 0; i < size; i++)
	{
		int next_value = (current->next) ? current->next->value : max;
		if ((value > prev_value && value < current->value) ||
			(prev_value > current->value && (value > prev_value || value < current->value)))
		{
			return (i);
		}
		prev_value = current->value;
		current = current->next;
		if (!current) current = stack;
	}
	return (0);
}

int calculate_cost(t_stack_node *stack_a, t_stack_node *stack_b, int pos_a, int pos_b)
{
	int size_a;
	int size_b;
	int cost_a;
	int cost_b;
	
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
	if ((pos_a <= size_a / 2 && pos_b <= size_b / 2) || 
		(pos_a > size_a / 2 && pos_b > size_b / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	} 
	else
		return (cost_a + cost_b);
}

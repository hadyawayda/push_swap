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
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack_node *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	iterate_over_stack(t_stack_node **stack, t_stack_node *current, int value,
		int prev_value)
{
	int	i;

	i = 0;
	while (i < stack_size(*stack))
	{
		if ((value > prev_value && value < current->value)
			|| (prev_value > current->value && (value > prev_value
					|| value < current->value)))
			return (i);
		prev_value = current->value;
		current = current->next;
		if (!current)
			current = *stack;
		i++;
	}
	return (0);
}

int	find_optimal_position_increasing(t_stack_node *stack, int value)
{
	t_stack_node	*current;
	int				position;
	int				prev_value;

	if (!stack)
		return (0);
	current = stack;
	position = 0;
	if (value < find_min(stack) || value > find_max(stack))
	{
		while (current && current->value != find_max(stack))
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
		prev_value = find_min(stack);
	return (iterate_over_stack(&stack, current, value, prev_value));
}

int	iterate_over_stack_decreasing(t_stack_node **stack, t_stack_node *current,
		int value, int prev_value)
{
	int	i;

	i = 0;
	while (i < stack_size(*stack))
	{
		if ((value < prev_value && value > current->value)
			|| (prev_value < current->value && (value < prev_value
					|| value > current->value)))
			return (i);
		prev_value = current->value;
		current = current->next;
		if (!current)
			current = *stack;
		i++;
	}
	return (0);
}

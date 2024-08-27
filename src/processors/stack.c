/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:23:30 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/26 23:17:55 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

t_stack_node	*stack_new(int content)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		error();
	new->value = content;
	new->next = NULL;
	return (new);
}

t_stack_node	*stack_add_back(t_stack_node **stack, t_stack_node *new)
{
	if (!stack)
		return (new);
	if (!*stack)
		*stack = new;
	else
		(ft_lstlast(*stack))->next = new;
	return (*stack);
}

void	merge_stacks(t_stack_node **a, t_stack_node **b)
{
	int	pos_a;
	int	size_a;

	while (*b)
	{
		pos_a = find_optimal_position_increasing(*a, (*b)->value);
		size_a = stack_size(*a);
		if (pos_a <= size_a / 2)
		{
			while (pos_a-- > 0)
				ra(a);
		}
		else
		{
			while (pos_a++ < size_a)
				rra(a);
		}
		pa(a, b);
	}
}

void	final_arrangement(t_stack_node **a)
{
	t_stack_node	*current;
	int				pos;
	int				min;
	int				size;

	current = *a;
	pos = 0;
	min = find_min(*a);
	size = stack_size(*a);
	while (current->value != min)
	{
		pos++;
		current = current->next;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
}

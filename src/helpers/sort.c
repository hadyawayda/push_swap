/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:47:57 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/26 23:38:27 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void	sort_two_stack(t_stack_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three_stack(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_large_stack(t_stack_node **a)
{
	t_stack_node	*b;

	b = NULL;
	if (stack_size(*a) > 4)
		pb(a, &b);
	pb(a, &b);
	while (stack_size(*a) > 3)
		calculate_cheapest(a, &b);
	sort_three_stack(a);
	merge_stacks(a, &b);
	final_arrangement(a);
}

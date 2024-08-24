/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:47:57 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/20 03:47:58 by hawayda          ###   ########.fr       */
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


// Helper function for small stacks
void sort_small_stack(t_stack_node **a) {
    int size = stack_size(*a);

    if (size <= 1) return;
    if (size == 2) {
        sort_two_stack(a);
        return;
    }
    if (size == 3) {
        sort_three_stack(a);
        return;
    }
}

void	sort_large_stack(t_stack_node **a)
{
	t_stack_node *b = NULL;
    
    // Pre-sorting for small stacks
    if (stack_size(*a) <= 5) {
        sort_small_stack(a);
        return;
    }
    
    // Initial push to B
    pb(a, &b);
    pb(a, &b);
    
    // Main sorting loop
    while (stack_size(*a) > 3) {
        calculate_cheapest(a, &b);
    }
    
    sort_three_stack(a);
    push_to_stackA(a, &b);
    final_arrangement(a);
}

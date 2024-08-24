/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:23:30 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/21 01:23:39 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

t_stack_node	*stack_new(int content)
{
	t_stack_node	*new;

	new = malloc(sizeof (t_stack_node));
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

void	push_to_stackA(t_stack_node **a, t_stack_node **b)
{
	while (*b) {
        int pos_a = find_optimal_position(*a, (*b)->value);
        int size_a = stack_size(*a);
        
        if (pos_a <= size_a / 2) {
            while (pos_a-- > 0) ra(a);
        } else {
            while (pos_a++ < size_a) rra(a);
        }
        pa(a, b);
    }
}

void	final_arrangement(t_stack_node **a)
{
	int min = find_min(*a);
    int size = stack_size(*a);
    t_stack_node *current = *a;
    int pos = 0;
    
    while (current->value != min) {
        pos++;
        current = current->next;
    }
    
    if (pos <= size / 2) {
        while (pos-- > 0) ra(a);
    } else {
        while (pos++ < size) rra(a);
    }
}

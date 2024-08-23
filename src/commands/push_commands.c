/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:22:01 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/20 02:22:01 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
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

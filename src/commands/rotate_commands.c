/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:22:09 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/20 02:22:10 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void rotate(t_stack_node **stack)
{
    if (!*stack || !(*stack)->next)
        return;
    t_stack_node *last = *stack;
    while (last->next)
        last = last->next;
    last->next = *stack;
    *stack = (*stack)->next;
    last->next->next = NULL;
}

// ra : rotate a - shift up all elements of stack a by 1
void ra(t_stack_node **a)
{
    rotate(a);
    write(1, "ra\n", 3);
    counter++;
}

// rb : rotate b - shift up all elements of stack b by 1
void rb(t_stack_node **b)
{
    rotate(b);
    write(1, "rb\n", 3);
    counter++;
}

// rr : ra and rb at the same time
void rr(t_stack_node **a, t_stack_node **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
    counter--;
}

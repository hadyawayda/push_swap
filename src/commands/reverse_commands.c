/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 04:19:11 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/20 04:19:12 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void reverse_rotate(t_stack_node **stack)
{
    if (!*stack || !(*stack)->next)
        return;
    t_stack_node *last = *stack;
    t_stack_node *second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    last->next = *stack;
    *stack = last;
    second_last->next = NULL;
}

// rra : reverse rotate a - shift down all elements of stack a by 1
void rra(t_stack_node **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
    counter++;
}

// rrb : reverse rotate b - shift down all elements of stack b by 1
void rrb(t_stack_node **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
    counter++;
}

// rrr : rra and rrb at the same time
void rrr(t_stack_node **a, t_stack_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
    counter--;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:22:17 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/20 02:22:18 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void swap(t_stack_node **stack)
{
    if (!*stack || !(*stack)->next)
        return;
    t_stack_node *temp = *stack;
    *stack = (*stack)->next;
    temp->next = (*stack)->next;
    (*stack)->next = temp;
}

void sa(t_stack_node **a)
{
    swap(a);
    write(1, "sa\n", 3);
    counter++;
}

void sb(t_stack_node **b)
{
    swap(b);
    write(1, "sb\n", 3);
    counter++;
}

void ss(t_stack_node **a, t_stack_node **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
    counter--;
}

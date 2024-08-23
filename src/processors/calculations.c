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
	int min = INT_MAX;
    while (stack) {
        if (stack->value < min) min = stack->value;
        stack = stack->next;
    }
    return min;
}

int find_max(t_stack_node *stack) {
    int max = INT_MIN;
    while (stack) {
        if (stack->value > max) max = stack->value;
        stack = stack->next;
    }
    return max;
}

int find_optimal_position(t_stack_node *stack, int value) {
    if (!stack) return 0;
    
    t_stack_node *current = stack;
    int position = 0;
    int min = find_min(stack);
    int max = find_max(stack);
    
    if (value < min || value > max) {
        // Find position of max
        while (current->value != max) {
            position++;
            current = current->next;
        }
        return (position + 1) % stack_size(stack);
    }
    
    int prev_value = stack->value;
    current = current->next;
    position = 1;
    
    while (current != stack) {
        if ((value > prev_value && value < current->value) ||
            (prev_value > current->value && (value > prev_value || value < current->value))) {
            return position;
        }
        prev_value = current->value;
        current = current->next;
        position++;
    }
    
    return 0;
}

int calculate_cost(t_stack_node *stack_a, t_stack_node *stack_b, int pos_a, int pos_b) {
    int size_a = stack_size(stack_a);
    int size_b = stack_size(stack_b);
    int cost_a = (pos_a <= size_a / 2) ? pos_a : size_a - pos_a;
    int cost_b = (pos_b <= size_b / 2) ? pos_b : size_b - pos_b;
    
    // Consider simultaneous rotations
    if ((pos_a <= size_a / 2 && pos_b <= size_b / 2) || 
        (pos_a > size_a / 2 && pos_b > size_b / 2)) {
        return (cost_a > cost_b) ? cost_a : cost_b;
    } else {
        return cost_a + cost_b;
    }
}

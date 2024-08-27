/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 03:55:36 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/27 03:55:37 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/push_swap.h"

void	swap_both(t_stack_node **a, t_stack_node **b)
{
	swap_m(a);
	swap_m(b);
}

void	rotate_both(t_stack_node **a, t_stack_node **b)
{
	rotate_m(a);
	rotate_m(b);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate_m(a);
	reverse_rotate_m(b);
}

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

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

// // This function returns the last element of the stack.
// t_stack_node	*ft_lstlast1(t_stack_node *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }


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

void merge_stackB_to_stackA(t_stack_node **a, t_stack_node **b) {
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



// // This function returns the size of the stack.
// int	ft_lstsize1(t_stack_node *lst)
// {
// 	size_t	i;

// 	i = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (i);
// }

// // This function finds and returns the smallest number
// // in the given stack.
// int	ft_min(t_stack_node *a)
// {
// 	int		i;

// 	i = a->value;
// 	while (a)
// 	{
// 		if (a->value < i)
// 			i = a->value;
// 		a = a->next;
// 	}
// 	return (i);
// }

// // This function finds and returns the biggest number
// // in the given stack.
// int	ft_max(t_stack_node *a)
// {
// 	int		i;

// 	i = a->value;
// 	while (a)
// 	{
// 		if (a->value > i)
// 			i = a->value;
// 		a = a->next;
// 	}
// 	return (i);
// }

// // This function checks the index of a number
// // 	 in the stack.
// int	ft_find_index(t_stack_node *a, int nbr)
// {
// 	int		i;

// 	i = 0;
// 	while (a->value != nbr)
// 	{
// 		i++;
// 		a = a->next;
// 	}
// 	// a->index = 0;
// 	return (i);
// }

// // This function finds the correct place of the number in stack_b.
// // In other words, it check what index number nbr_push will get 
// // after it is being pushed to the stack_b.
// int	ft_find_place_b(t_stack_node *stack_b, int nbr_push)
// {
// 	int		i;
// 	t_stack_node	*tmp;

// 	i = 1;
// 	if (nbr_push > stack_b->value && nbr_push < ft_lstlast1(stack_b)->value)
// 		i = 0;
// 	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
// 		i = ft_find_index(stack_b, ft_max(stack_b));
// 	else
// 	{
// 		tmp = stack_b->next;
// 		while (stack_b->value < nbr_push || tmp->value > nbr_push)
// 		{
// 			stack_b = stack_b->next;
// 			tmp = stack_b->next;
// 			i++;
// 		}
// 	}
// 	return (i);
// }

// // This function finds the correct place of the number in stack_a.
// // In other words, it check what index number nbr_push will get 
// // after it is being pushed to the stack_a.
// int	ft_find_place_a(t_stack_node *stack_a, int nbr_push)
// {
// 	int		i;
// 	t_stack_node	*tmp;

// 	i = 1;
// 	if (nbr_push < stack_a->value && nbr_push > ft_lstlast1(stack_a)->value)
// 		i = 0;
// 	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
// 		i = ft_find_index(stack_a, ft_min(stack_a));
// 	else
// 	{
// 		tmp = stack_a->next;
// 		while (stack_a->value > nbr_push || tmp->value < nbr_push)
// 		{
// 			stack_a = stack_a->next;
// 			tmp = stack_a->next;
// 			i++;
// 		}
// 	}
// 	return (i);
// }

// // This function calculates how many times 
// // we should rotate the stacks together.
// // Because after a certain amoun of rotate, we will
// // proceed only with one stack rotation.
// int	ft_case_rarb(t_stack_node *a, t_stack_node *b, int c)
// {
// 	int	i;

// 	i = ft_find_place_b(b, c);
// 	if (i < ft_find_index(a, c))
// 		i = ft_find_index(a, c);
// 	return (i);
// }

// // This function calculates how many times we should rotate the stacks together.
// // Because after a certain amoun of rotate, we will proceed only with one stack
// // rotation. Since here we have reverse rotate,rather than index number,
// // we check reverse index number which is 
// // calculated by list_size - index_number.
// int	ft_case_rrarrb(t_stack_node *a, t_stack_node *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_place_b(b, c))
// 		i = ft_lstsize1(b) - ft_find_place_b(b, c);
// 	if ((i < (ft_lstsize1(a) - ft_find_index(a, c))) && ft_find_index(a, c))
// 		i = ft_lstsize1(a) - ft_find_index(a, c);
// 	return (i);
// }

// // Again, this function makes similar calculations.
// // This function do same calculations for rra+rb case.
// int	ft_case_rrarb(t_stack_node *a, t_stack_node *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_index(a, c))
// 		i = ft_lstsize1(a) - ft_find_index(a, c);
// 	i = ft_find_place_b(b, c) + i;
// 	return (i);
// }

// // Again, this function makes similar calculations.
// // This function do same calculations for ra+rrb case.
// int	ft_case_rarrb(t_stack_node *a, t_stack_node *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_place_b(b, c))
// 		i = ft_lstsize1(b) - ft_find_place_b(b, c);
// 	i = ft_find_index(a, c) + i;
// 	return (i);
// }


// // This function calculates the required amount of rotation.
// // Calculations are done for ra+rb case.
// int	ft_case_rarb_a(t_stack_node *a, t_stack_node *b, int c)
// {
// 	int	i;

// 	i = ft_find_place_a(a, c);
// 	if (i < ft_find_index(b, c))
// 		i = ft_find_index(b, c);
// 	return (i);
// }

// // This function calculates the required amount of rotation.
// // Calculations are done for rra+rrb case.
// int	ft_case_rrarrb_a(t_stack_node *a, t_stack_node *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_place_a(a, c))
// 		i = ft_lstsize1(a) - ft_find_place_a(a, c);
// 	if ((i < (ft_lstsize1(b) - ft_find_index(b, c))) && ft_find_index(b, c))
// 		i = ft_lstsize1(b) - ft_find_index(b, c);
// 	return (i);
// }

// // This function calculates the required amount of rotation.
// // Calculations are done for ra+rrb case.
// int	ft_case_rarrb_a(t_stack_node *a, t_stack_node *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_index(b, c))
// 		i = ft_lstsize1(b) - ft_find_index(b, c);
// 	i = ft_find_place_a(a, c) + i;
// 	return (i);
// }

// // This function calculates the required amount of rotation.
// // Calculations are done for rra+rb case.
// int	ft_case_rrarb_a(t_stack_node *a, t_stack_node *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_place_a(a, c))
// 		i = ft_lstsize1(a) - ft_find_place_a(a, c);
// 	i = ft_find_index(b, c) + i;
// 	return (i);
// }


// int	ft_rotate_type_ba(t_stack_node *a, t_stack_node *b)
// {
// 	int		i;
// 	t_stack_node	*tmp;

// 	tmp = b;
// 	i = ft_case_rrarrb_a(a, b, b->value);
// 	while (tmp)
// 	{
// 		if (i > ft_case_rarb_a(a, b, tmp->value))
// 			i = ft_case_rarb_a(a, b, tmp->value);
// 		if (i > ft_case_rrarrb_a(a, b, tmp->value))
// 			i = ft_case_rrarrb_a(a, b, tmp->value);
// 		if (i > ft_case_rarrb_a(a, b, tmp->value))
// 			i = ft_case_rarrb_a(a, b, tmp->value);
// 		if (i > ft_case_rrarb_a(a, b, tmp->value))
// 			i = ft_case_rrarb_a(a, b, tmp->value);
// 		tmp = tmp->next;
// 	}
// 	return (i);
// }

// // This function calculate and decides which rotation
// // combination is best to use to sort the stack. Of
// // course, after rotation there is always one push
// // operation is left to do which i embeded to code.
// // Function is used during push from A to B.
// int	ft_rotate_type_ab(t_stack_node *a, t_stack_node *b)
// {
// 	int		i;
// 	t_stack_node	*tmp;

// 	tmp = a;
// 	i = ft_case_rrarrb(a, b, a->value);
// 	while (tmp)
// 	{
// 		if (i > ft_case_rarb(a, b, tmp->value))
// 			i = ft_case_rarb(a, b, tmp->value);
// 		if (i > ft_case_rrarrb(a, b, tmp->value))
// 			i = ft_case_rrarrb(a, b, tmp->value);
// 		if (i > ft_case_rarrb(a, b, tmp->value))
// 			i = ft_case_rarrb(a, b, tmp->value);
// 		if (i > ft_case_rrarb(a, b, tmp->value))
// 			i = ft_case_rrarb(a, b, tmp->value);
// 		tmp = tmp->next;
// 	}
// 	return (i);
// }


// // This function rotates both stack_a and stack_b
// // in the same direction as required amount.
// int	ft_apply_rarb(t_stack_node **a, t_stack_node **b, int c, char s)
// {
// 	if (s == 'a')
// 	{
// 		while ((*a)->value != c && ft_find_place_b(*b, c) > 0)
// 			rr(a, b);
// 		while ((*a)->value != c)
// 			ra(a);
// 		while (ft_find_place_b(*b, c) > 0)
// 			rb(b);
// 		pb(a, b);
// 	}
// 	else
// 	{
// 		while ((*b)->value != c && ft_find_place_a(*a, c) > 0)
// 			rr(a, b);
// 		while ((*b)->value != c)
// 			rb(b);
// 		while (ft_find_place_a(*a, c) > 0)
// 			ra(a);
// 		pa(a, b);
// 	}
// 	return (-1);
// }

// // This function rotate both stack_a and stack_b in the
// // reverse direction as required amount.
// int	ft_apply_rrarrb(t_stack_node **a, t_stack_node **b, int c, char s)
// {
// 	if (s == 'a')
// 	{
// 		while ((*a)->value != c && ft_find_place_b(*b, c) > 0)
// 			rrr(a, b);
// 		while ((*a)->value != c)
// 			rra(a);
// 		while (ft_find_place_b(*b, c) > 0)
// 			rrb(b);
// 		pb(a, b);
// 	}
// 	else
// 	{
// 		while ((*b)->value != c && ft_find_place_a(*a, c) > 0)
// 			rrr(a, b);
// 		while ((*b)->value != c)
// 			rrb(b);
// 		while (ft_find_place_a(*a, c) > 0)
// 			rra(a);
// 		pa(a, b);
// 	}
// 	return (-1);
// }

// // This function rotate the stack_a in reverse direction,
// // the stack_b in oppsite direction of stack_a as required amount.
// int	ft_apply_rrarb(t_stack_node **a, t_stack_node **b, int c, char s)
// {
// 	if (s == 'a')
// 	{
// 		while ((*a)->value != c)
// 			rra(a);
// 		while (ft_find_place_b(*b, c) > 0)
// 			rb(b);
// 		pb(a, b);
// 	}
// 	else
// 	{
// 		while (ft_find_place_a(*a, c) > 0)
// 			rra(a);
// 		while ((*b)->value != c)
// 			rb(b);
// 		pa(a, b);
// 	}
// 	return (-1);
// }

// // This function rotate the stack_b in reverse direction,
// // the stack_a in oppsite direction of stack_a as required amount.
// int	ft_apply_rarrb(t_stack_node **a, t_stack_node **b, int c, char s)
// {
// 	if (s == 'a')
// 	{
// 		while ((*a)->value != c)
// 			ra(a);
// 		while (ft_find_place_b(*b, c) > 0)
// 			rrb(b);
// 		pb(a, b);
// 	}
// 	else
// 	{
// 		while (ft_find_place_a(*a, c) > 0)
// 			ra(a);
// 		while ((*b)->value != c)
// 			rrb(b);
// 		pa(a, b);
// 	}
// 	return (-1);
// }


// void	merge_stackB_to_stackA(t_stack_node **a, t_stack_node **b)
// {
// 	int		i;
// 	t_stack_node	*tmp;

// 	while (*b)
// 	{
// 		tmp = *b;
// 		i = ft_rotate_type_ba(*a, *b);
// 		while (i >= 0)
// 		{
// 			if (i == ft_case_rarb_a(*a, *b, tmp->value))
// 				i = ft_apply_rarb(a, b, tmp->value, 'b');
// 			else if (i == ft_case_rarrb_a(*a, *b, tmp->value))
// 				i = ft_apply_rarrb(a, b, tmp->value, 'b');
// 			else if (i == ft_case_rrarrb_a(*a, *b, tmp->value))
// 				i = ft_apply_rrarrb(a, b, tmp->value, 'b');
// 			else if (i == ft_case_rrarb_a(*a, *b, tmp->value))
// 				i = ft_apply_rrarb(a, b, tmp->value, 'b');
// 			else
// 				tmp = tmp->next;
// 		}
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:38:52 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/19 00:38:53 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

t_stack_node		*pre_process(int argc, char **argv);
t_stack_node		*stack_new(int content);
t_stack_node		*ft_lstlast(t_stack_node *lst);
t_stack_node		*stack_add_back(t_stack_node **stack, t_stack_node *new);

bool				checkdup(t_stack_node *a);

int					checksorted(t_stack_node *a);
int					atoi_modified(char *str);

void				process(t_stack_node **a, char **list, int i);
void				subprocess(t_stack_node **a, char **argv);
void				sort(t_stack_node **a);
void				ft_free(t_stack_node **a);
void				ft_freestr(char **lst);
void				error(void);
void				sort_two_stack(t_stack_node **a);
void				sort_three_stack(t_stack_node **a);
void				sort_large_stack(t_stack_node **a);
void				push(t_stack_node **a, t_stack_node **b);
void				push_a(t_stack_node **a, t_stack_node **b);
void				push_b(t_stack_node **a, t_stack_node **b);
void				ra(t_stack_node **a);
void				rb(t_stack_node **b);
void				rr(t_stack_node **a, t_stack_node **b);
void				rra(t_stack_node **a);
void				rrb(t_stack_node **b);
void				rrr(t_stack_node **a, t_stack_node **b);
void				sa(t_stack_node **a);
void				sb(t_stack_node **b);
void				ss(t_stack_node **a, t_stack_node **b);

#endif
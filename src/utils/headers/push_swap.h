/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawayda <hawayda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:38:52 by hawayda           #+#    #+#             */
/*   Updated: 2024/08/26 06:38:50 by hawayda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

t_stack_node			*pre_process(int argc, char **argv);
t_stack_node			*stack_new(int content);
t_stack_node			*ft_lstlast(t_stack_node *lst);
t_stack_node			*stack_add_back(t_stack_node **stack,
							t_stack_node *new);

int						find_min(t_stack_node *a);
int						find_max(t_stack_node *stack);
int						atoi_modified(char *str);
int						stack_size(t_stack_node *a);
int						find_optimal_position_increasing(t_stack_node *a, int value);
int						calculate_cost(t_stack_node *stack_a,
							t_stack_node *stack_b, int position_a,
							int position_b);
int						iterate_over_stack_decreasing(t_stack_node **stack, t_stack_node *current, int value, int prev_value);

bool					checkdup(t_stack_node *a);
bool					checksorted(t_stack_node *a);

void					rotate_stacks(t_stack_node **stack_a,
							t_stack_node **stack_b, int pos_a, int pos_b);
void					print_stack(t_stack_node *a);
void					merge_stacks(t_stack_node **a, t_stack_node **b);
void					final_arrangement(t_stack_node **a);
void					calculate_cheapest(t_stack_node **a, t_stack_node **b);
void					process(t_stack_node **a, char **list, int i);
void					subprocess(t_stack_node **a, char **argv);
void					sort(t_stack_node **a);
void					ft_free(t_stack_node **a);
void					ft_freestr(char **lst);
void					error(void);
void					sort_two_stack(t_stack_node **a);
void					sort_three_stack(t_stack_node **a);
void					sort_large_stack(t_stack_node **a);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **a, t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);
void					ft_error_ch(void);

#endif
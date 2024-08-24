#include "../utils/headers/push_swap.h"

void	rotate_both_rr(t_stack_node **stack_a, t_stack_node **stack_b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0)
	{
		rr(stack_a, stack_b);
		(*pos_a)--;
		(*pos_b)--;
	}
	while (*pos_a > 0)
	{
		ra(stack_a);
		(*pos_a)--;
	}
	while (*pos_b > 0)
	{
		rb(stack_b);
		(*pos_b)--;
	}
}

void	reverse_rotate_both_rrr(t_stack_node **stack_a, t_stack_node **stack_b, int *pos_a, int *pos_b, int size_a, int size_b)
{
	while (*pos_a < size_a && *pos_b < size_b)
	{
		rrr(stack_a, stack_b);
		(*pos_a)++;
		(*pos_b)++;
	}
	while (*pos_a < size_a)
	{
		rra(stack_a);
		(*pos_a)++;
	}
	while (*pos_b < size_b)
	{
		rrb(stack_b);
		(*pos_b)++;
	}
}

void	rotate_stack_a(t_stack_node **stack_a, int pos_a, int size_a)
{
    if (pos_a <= size_a / 2)
	{
        while (pos_a > 0)
		{
            ra(stack_a);
            pos_a--;
        }
    }
	else
	{
        while (pos_a < size_a)
		{
            rra(stack_a);
            pos_a++;
        }
    }
}

void	rotate_stack_b(t_stack_node **stack_b, int pos_b, int size_b)
{
    if (pos_b <= size_b / 2)
	{
        while (pos_b > 0)
		{
            rb(stack_b);
            pos_b--;
        }
    } else {
        while (pos_b < size_b)
		{
            rrb(stack_b);
            pos_b++;
        }
    }
}

void	rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b, int pos_a, int pos_b, int size_a) {
	int size_b;

	size_b = stack_size(*stack_b);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
		rotate_both_rr(stack_a, stack_b, &pos_a, &pos_b);
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
		reverse_rotate_both_rrr(stack_a, stack_b, &pos_a, &pos_b, size_a, size_b);
	else {
		rotate_stack_a(stack_a, pos_a, size_a);
    	rotate_stack_b(stack_b, pos_b, size_b);
	}
}

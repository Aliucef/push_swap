#include "push_swap_operations.h"

void	swap(t_list *stack, char which, t_ops *ops)
{
	int	swapper;

	if (!stack || !stack->next)
		return;
	swapper = stack->content;
	stack->content = stack->next->content;
	stack->next->content = swapper;
	if (which == 'a')
	{
		ft_printf(1, "sa\n");
		ops->sa++;
	}
	else if (which == 'b')
	{
		ft_printf(1, "sb\n");
		ops->sb++;
	}
}

void	swap_both(t_list *stack_a, t_list *stack_b, t_ops *ops)
{
	int	swapper;

	if (stack_a && stack_a->next)
	{
		swapper = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = swapper;
	}
	if (stack_b && stack_b->next)
	{
		swapper = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = swapper;
	}
	ft_printf(1, "ss\n");
	ops->ss++;
}

void	rotate(t_list **stack, char which, t_ops *ops)
{
	t_list	*last;
	t_list	*first;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
	if (which == 'a')
	{
		ft_printf(1, "ra\n");
		ops->ra++;
	}
	else if (which == 'b')
	{
		ft_printf(1, "rb\n");
		ops->rb++;
	}
}

void	rotate_both(t_list **stack_a, t_list **stack_b, t_ops *ops)
{
	t_list	*last;
	t_list	*first;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		*stack_a = first->next;
		first->next = NULL;
		last = ft_lstlast(*stack_a);
		last->next = first;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		*stack_b = first->next;
		first->next = NULL;
		last = ft_lstlast(*stack_b);
		last->next = first;
	}
	ft_printf(1, "rr\n");
	ops->rr++;
}

void	reverse_rotate(t_list **stack, char which, t_ops *ops)
{
	t_list	*before_last;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (which == 'a')
	{
		ft_printf(1, "rra\n");
		ops->rra++;
	}
	else if (which == 'b')
	{
		ft_printf(1, "rrb\n");
		ops->rrb++;
	}
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b, t_ops *ops)
{
	t_list	*before_last;
	t_list	*last;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		before_last = *stack_a;
		while (before_last->next->next)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		before_last = *stack_b;
		while (before_last->next->next)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
	ft_printf(1, "rrr\n");
	ops->rrr++;
}

void	push(t_list **stack_a, t_list **stack_b, char which, t_ops *ops)
{
	t_list	*swap;

	if (!*stack_a || !stack_a)
		return;
	swap = *stack_a;
	*stack_a = (*stack_a)->next;
	swap->next = *stack_b;
	*stack_b = swap;
	if (which == 'b')
	{
		ft_printf(1, "pb\n");
		ops->pb++;
	}
	else
	{
		ft_printf(1, "pa\n");
		ops->pa++;
	}
}

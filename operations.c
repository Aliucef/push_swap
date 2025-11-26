/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:12:38 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/26 17:46:19 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"

void	swap(t_list *stack)
{
	int	swapper;

	if (!stack || !stack->next)
		return ;
	swapper = stack->content;
	stack->content = stack->next->content;
	stack->next->content = swapper;
}

void	swap_both(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*before_last;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:10:44 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/27 09:45:12 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"

// bubble sort (2000+ operations for 100 element)
void	simple_sort(t_list *stack_a)
{
	t_list	*temp_head_holder;
	int counter;

	counter = 0;
	temp_head_holder = stack_a;
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
		{
			swap(stack_a);
			ft_printf("sa\n");
			counter++;
			stack_a = temp_head_holder;
		}
		stack_a = stack_a->next;
	}
	stack_a = temp_head_holder;
	ft_printf("finished\n");
	ft_printf("counter :%d\n", counter);
}
// selection sort
int	selection_sort_operation(t_list **stack_a , t_list **stack_b)
{
	int		min;
	int		path;
	int		counter;
	t_list	*head_holder;
	int		which_reverse;
	int		ops_counter;

	ops_counter = 0;
	which_reverse = 0;
	counter = 0;
	path = 0;
	head_holder = *stack_a;
	min = (*stack_a)->content;
	while (*stack_a)
	{
		if((*stack_a)->content < min)
		{
			min = (*stack_a)->content;
			path = counter;
		}
		counter++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_holder;
	if (path > counter / 2)
	{
		path = counter - path;
		which_reverse = 1;
	}
	while (path--)
	{
		if(which_reverse)
		{
			reverse_rotate(stack_a); ft_printf("rra\n"); ops_counter++;
		}
		else
		{
			rotate(stack_a); ft_printf("ra\n"); ops_counter++;
		}
	}
	push(stack_a, stack_b); ft_printf("pa\n"); ops_counter++;
	return ops_counter;
}

void	selection_sort(t_list **stack_a, t_list **stack_b)
{
	int ops_counter = 0;
	while(*stack_a)
	{
		ops_counter+=selection_sort_operation(stack_a, stack_b);
	}
	while (*stack_b)
	{
		push(stack_b, stack_a);ft_printf("pb\n"); ops_counter++;
	}
	ft_printf("final operations number : %d \n" ,ops_counter++);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_selection_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:10:44 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/28 13:16:30 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"
#include "sorting_header.h"

static int	find_min_and_path(t_list *stack, int *min, int *path, int *count)
{
	int		counter;
	int		current_min;
	int		min_path;
	int		is_sorted;

	min_path = 0;
	counter = 0;
	is_sorted = 0;
	current_min = stack->content;
	while (stack)
	{
		if (stack->content < current_min)
		{
			current_min = stack->content;
			min_path = counter;
		}
		if(stack->next)
		{
			if (stack->content >  stack->next->content)
				is_sorted = 1;
		}
		counter++;
		stack = stack->next;
	}
	*min = current_min;
	*path = min_path;
	*count = counter;
	return (is_sorted);
}

static void	adjust_path_direction(int *path, int count, int *which_reverse)
{
	*which_reverse = 0;
	if (*path > count / 2)
	{
		*path = count - *path;
		*which_reverse = 1;
	}
}

static int	apply_rotations(t_list **stack_a, int path, int which_reverse)
{
	int	ops;

	ops = 0;
	while (path--)
	{
		if (which_reverse)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
		}
		else
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
		ops++;
	}
	return (ops);
}

int	selection_sort_operation(t_list **stack_a,
		t_list **stack_b, int ops_counter, int *is_sorted)
{
	int		min;
	int		path;
	int		count;
	int		which_reverse;

	if(*is_sorted)
	{
		ft_printf("is_sorted : %d", *is_sorted);
		*is_sorted = find_min_and_path(*stack_a, &min, &path, &count);
	}
	else
		return (-1);
	adjust_path_direction(&path, count, &which_reverse);
	ops_counter = apply_rotations(stack_a, path, which_reverse);
	push(stack_a, stack_b);
	ft_printf("pb\n");
	return (ops_counter + 1);
}

void	selection_sort(t_list **stack_a, t_list **stack_b)
{
	int	ops_counter;
	int	inner_counter;
	int	is_sorted;

	is_sorted = 1;
	// if (!check_if_sorted(*stack_a))
	// {
	ops_counter = 0;
	inner_counter = 0;
	while (*stack_a)
	{
		ops_counter += selection_sort_operation(stack_a,
				stack_b, inner_counter, &is_sorted);
	}
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
		ops_counter++;
	}
	// }
}
	// ft_printf("final operations number : %d \n", ops_counter);


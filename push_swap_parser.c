/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:20:51 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/26 17:52:54 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap_operations.h"
#include <stdio.h>

static void	fill_stack_a(char *argv, t_list **stack_a)
{
	t_list	*node;

	node = ft_lstnew(ft_atoi(argv));
	ft_lstadd_back(stack_a, node);
	while (node->next)
	{
		node = node->next;
	}
}

static int	is_dup(int to_be_compared, char **list, int argc, int position)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (to_be_compared == ft_atoi(list[i]) && i != position)
			return (1);
	}
	return (0);
}

int	check_if_input_valid(char **argv, int argc, t_list **stack_a)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		return (0);
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		}
		if (is_dup(ft_atoi(argv[i]), argv, argc, i))
			return (0);
		fill_stack_a(argv[i], stack_a);
	}
	return (1);
}

double	compute_disorder(t_list *stack_a)
{
	double	mistakes;
	double	total_pairs;
	t_list	*temp;

	mistakes = 0.0;
	total_pairs = 0.0;
	while (stack_a->next)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (stack_a->content > temp->content)
				mistakes += 1;
			total_pairs += 1;
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (mistakes / total_pairs);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	double	disorder;

	disorder = 0.0;
	stack_b = NULL;
	stack_a = NULL;
	if (!check_if_input_valid(argv, argc, &stack_a))
		return (ft_printf("Error"), 0);
	ft_printf("hello\n");
	disorder = compute_disorder(stack_a);
	printf("this is disorder %f\n", disorder);
	reverse_rotate(&stack_a);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	swap_both(stack_a, stack_b);
	while (stack_a)
	{
		ft_printf("stack a : %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	while (stack_b)
	{
		ft_printf("stack b : %d\n", stack_b->content);
		stack_b = stack_b->next;
	}
	return (0);
}

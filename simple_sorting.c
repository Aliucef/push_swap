/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:10:44 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/26 18:46:32 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"

void	simple_sort(t_list *stack_a)
{
	t_list	*temp_head_holder;

	temp_head_holder = stack_a;
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
		{
			swap(stack_a);
			ft_printf("sa\n");
			stack_a = temp_head_holder;
		}
		stack_a = stack_a->next;
	}
	stack_a = temp_head_holder;
	ft_printf("finished\n");
}

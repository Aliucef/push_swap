/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:39:41 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/26 17:46:39 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*swap;

	if (!*stack_a || !stack_a)
		return ;
	swap = *stack_a;
	*stack_a = (*stack_a)->next;
	swap->next = *stack_b;
	*stack_b = swap;
}

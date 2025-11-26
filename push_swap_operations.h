/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:39:19 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/26 17:45:38 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPERATIONS_H
# define PUSH_SWAP_OPERATIONS_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"

void	swap(t_list *stack);
void	swap_both(t_list *stack_a, t_list *stack_b);
void	rotate(t_list **stack);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:13:20 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/26 11:51:15 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*current;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst != NULL)
// 	{
// 		current = (*lst)->next;
// 		del((*lst)->content);
// 		free(*lst);
// 		*lst = current;
// 	}
// 	*lst = NULL;
// }

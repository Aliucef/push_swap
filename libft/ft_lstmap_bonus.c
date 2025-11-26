/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:13:50 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/26 11:51:22 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
// 			void (*del)(void *))
// {
// 	t_list	*new_list;
// 	t_list	*node;
// 	void	*content;

// 	if (!lst || !f || !del)
// 		return (NULL);
// 	new_list = NULL;
// 	while (lst != NULL)
// 	{
// 		content = f(lst->content);
// 		node = ft_lstnew(content);
// 		if (!node)
// 		{
// 			del(content);
// 			ft_lstclear(&new_list, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&new_list, node);
// 		lst = lst->next;
// 	}
// 	return (new_list);
// }

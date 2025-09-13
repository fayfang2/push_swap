/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:54:07 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:51:26 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*count;
	t_list	*new;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	count = lst;
	while (count)
	{
		content = f(count -> content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		count = count->next;
	}
	return (new);
}

/* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*n;
	t_list	*count;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	count = lst;
	while (count)
	{
		n = ft_lstnew(f(count->content));
		if (!n)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, n);
		count = count->next;
	}
	return (new_lst);
}
 */
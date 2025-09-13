/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:53:55 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:51:07 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;
	t_list	*count;

	if (!lst || !del)
		return ;
	count = *lst;
	while (count)
	{
		clear = count -> next;
		ft_lstdelone(count, del);
		count = clear;
	}
	*lst = NULL;
}

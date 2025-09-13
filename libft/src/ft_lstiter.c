/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:54:02 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:51:21 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*count;

	if (!lst || !f)
		return ;
	count = lst;
	while (count)
	{
		f(count -> content);
		count = count -> next;
	}
}

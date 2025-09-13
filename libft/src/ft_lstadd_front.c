/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:53:52 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:51:04 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_front(t_list	**lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

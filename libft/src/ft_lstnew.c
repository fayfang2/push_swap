/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:54:10 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:51:30 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst -> content = content;
	lst -> next = NULL;
	return (lst);
}

/* #include <stdio.h>

static	void	ft_printlst(struct s_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)(lst -> content));
		lst = lst -> next;
	}
}

int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*lst;
	void	*content;

	content = (char *)"you?";

	first = (t_list *)malloc(sizeof(t_list));
	first -> content = "Hello";

	second = (t_list *)malloc(sizeof(t_list));
	second -> content = "How";

	third = (t_list *)malloc(sizeof(t_list));
	third -> content = "are";

	first -> next = second;
	second -> next = third;
	third -> next = NULL;

	lst = ft_lstnew(content);
	
	ft_printlst(first);
	return (0);
} */
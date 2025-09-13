/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:54:13 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:51:32 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*count;

	if (!lst)
		return (0);
	size = 0;
	count = lst;
	while (count)
	{
		size++;
		count = count -> next;
	}
	return (size);
}
/* 
#include <stdio.h>

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
	t_list	**lst;
	t_list	*new;
	void	*content;
	int		size;

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

	new = ft_lstnew(content);
	*lst = first;
	ft_lstadd_front(lst, new);
	size = ft_lstsize(*lst);

	printf("List size is: %d\n", size);
	ft_printlst(*lst);
	return (0);
} */
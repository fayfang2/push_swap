/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:54:04 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:51:24 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
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
	t_list	**lst;
	t_list	*new;
	t_list	*last;
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
	lst = &first;
	ft_lstadd_front(lst, new);
	size = ft_lstsize(*lst);
	last = ft_lstlast(*lst);

	printf("List size is: %d\n", size);
	printf("The last node of the list is: %s\n", (char *)(last -> content));
	ft_printlst(*lst);
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:12 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:54:28 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (!little[j + 1])
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	// char	*str1a;
	char	*str2a;
	const char	str[] = "Where are we going today?";
	const char	str1[500] = "Where are we going today?";
	const char	to_find[] = "";
	size_t	len;
	len = 5;

	// str1a = strnstr(str1, to_find, len);
	str2a = ft_strnstr(str1, to_find, len);

	printf("String: %s\n", str);
	printf("To_find: %s\n", to_find);
	// printf("Test with strnstr: %s\n", str1a);
	printf("Test with ft_strnstr: %s\n", str2a);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:27 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:53:44 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

/* char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (unsigned char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)s + i);
} */

/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	*str1a;
	const char	*str2a;
	char	str[] = "Where are we going today?";
	char	str1[500] = "Where are we going today?";
	char	str2[500] = "Where are we going today?";
	int		to_find = '1';

	str1a = strchr(str1, to_find);
	str2a = ft_strchr(str2, to_find);

	printf("String: %s\n", str);
	printf("To_find: %c\n", to_find);
	printf("Test with strchr: %s\n", str1a);
	printf("Test with ft_strchr: %s\n", str2a);
} */
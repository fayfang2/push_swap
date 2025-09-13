/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:23 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:53:58 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	des;
	size_t	srs;
	size_t	tos;
	size_t	i;

	des = ft_strlen(dest);
	srs = ft_strlen(src);
	tos = 0;
	i = 0;
	if (size > des)
		tos = des + srs;
	else
		return (srs + size);
	while (src[i] && i < (size - des - 1))
	{
		dest[des + i] = src[i];
		i++;
	}
	dest[des + i] = '\0';
	return (tos);
}

/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	int	nb;
	int	s1;
	int	s2;
	char	src[] = " bellyboo";
	char	dest[] = "Fay fang";
	char	dest1[500] = "Fay Fang";
	char	dest2[500] = "Fay Fang";

	nb = 11;
	s1 = strlcat(dest1, src, nb);
	s2 = ft_strlcat(dest2, src, nb);

	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	printf("Test with strlcat: %s, size = %d\n", dest1, s1);
	printf("Test with ft_strlcat: %s, size = %d\n", dest2, s2);
} */
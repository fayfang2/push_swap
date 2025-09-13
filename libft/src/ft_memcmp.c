/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:39 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:51:39 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	if (n == 0)
		return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (p1[i] == p2[i] && i < n - 1)
		i++;
	return (p1[i] - p2[i]);
}

/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	*s1;
	const char	*s2;
	size_t	n;
	int	diff1;
	int	diff2;

	s1 = "Hellooaao";
	s2 = "HelloooO";
	n = 7;
	diff1 = memcmp(s1, s2, n);
	diff2 = ft_memcmp(s1, s2, n);

	printf("The diff using memcmp is:%d\n", diff1);
	printf("The diff using ft_memcmp is:%d\n", diff2);
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:15 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:54:25 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	int	n;
	int	diff1;
	int	diff2;

	s1 = "Hellooao";
	s2 = "HelloOAo";
	n = 6;
	diff1 = strncmp(s1, s2, n);
	diff2 = ft_strncmp(s1, s2, n);

	printf("The diff using strncmp is:%d\n", diff1);
	printf("The diff using ft_strncmp is:%d\n", diff2);
	return (0);
} */
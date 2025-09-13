/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:10:26 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:54:40 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	size;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= (size_t)start)
		return (ft_strdup(""));
	if (start + len > slen)
		size = slen - start;
	else
		size = len;
	substr = malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, size + 1);
	return (substr);
}

/*
#include <stdio.h>
int main(void)
{
	char intro[] = "my name is fay fang";

	char *name = ft_substr(intro, 5, 20);
	printf("%s\n", name);
}
 */

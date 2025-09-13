/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:10 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:54:30 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (!c || (unsigned char)c == '\0')
		return ((char *)s + i);
	while (i--)
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	return (NULL);
}

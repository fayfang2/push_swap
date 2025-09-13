/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:37 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:51:42 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*s;
	size_t			i;

	p = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}

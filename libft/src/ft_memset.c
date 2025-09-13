/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:30 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:52:53 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = str;
	i = 0;
	while (i < n)
		p[i++] = c;
	return (str);
}

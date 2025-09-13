/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:25 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:53:46 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s) + 1;
	dup = malloc(sizeof(char) * len);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len);
	return (dup);
}

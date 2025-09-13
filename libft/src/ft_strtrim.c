/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:29:03 by fde-waal          #+#    #+#             */
/*   Updated: 2025/08/09 10:54:33 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (j && ft_strchr(set, s1[j]))
		j--;
	strtrim = ft_substr(s1, i, j - i + 1);
	return (strtrim);
}

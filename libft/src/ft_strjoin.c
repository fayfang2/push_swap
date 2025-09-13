/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:11:41 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:53:52 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = malloc(sizeof(char) * len);
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, len);
	ft_strlcat(strjoin, s2, len);
	return (strjoin);
}

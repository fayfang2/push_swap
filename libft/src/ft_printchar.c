/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:48:32 by fayfang           #+#    #+#             */
/*   Updated: 2025/08/09 12:20:00 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printchar(char c)
{
	ssize_t	count;

	count = write(1, &c, 1);
	return (count);
}

int	ft_printstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (ft_printstr("(null)"));
	while (str[i])
		count += ft_printchar(str[i++]);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:55 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 13:00:43 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	num;
	long int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		num = (num * 10) + (nptr[i++] - '0');
	return (num * sign);
}

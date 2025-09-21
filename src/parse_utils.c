/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:42:17 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/21 08:56:12 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(long *a, long *b)
{
	long	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

long	ft_atol(const char *s)
{
	size_t	i;
	long	sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (ft_issign(s[i]))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num * sign);
}

int	check_format(char *input)
{
	size_t	i;

	i = 0;
	while (ft_isspace(input[i]))
		i++;
	if (ft_issign(input[i]))
		i++;
	while (input[i])
	{
		if (!ft_isdigit(input[i++]))
			return (0);
	}
	return (1);
}

int	check_sorted(long *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(long *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] == array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

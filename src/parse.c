/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:29:48 by fayfang           #+#    #+#             */
/*   Updated: 2025/10/23 17:38:29 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	parse(size_t size, char **argv, long *indices)
{
	long	*unsorted;
	long	*sorted;
	size_t	i;

	i = 0;
	unsorted = init_array(size);
	sorted = init_array(size);
	while (i < size)
	{
		if (!check_format(argv[i + 1]) || !ft_strcmp(argv[i + 1], "-")
			|| !ft_strcmp(argv[i + 1], "+"))
			return (free_arrays(unsorted, sorted));
		unsorted[i] = ft_atol(argv[i + 1]);
		if (unsorted[i] < INT_MIN || unsorted[i] > INT_MAX)
			return (free_arrays(unsorted, sorted));
		sorted[i] = unsorted[i];
		i++;
	}
	if (!checks(unsorted, sorted, indices, size))
		return (0);
	free_arrays(unsorted, sorted);
	return (1);
}

int	checks(long *unsorted, long *sorted, long *indices, size_t size)
{
	if (check_sorted(unsorted, size))
		return (free_arrays(unsorted, sorted));
	quicksort(sorted, 0, size - 1);
	if (check_dup(sorted, size))
		return (free_arrays(unsorted, sorted));
	normalize(unsorted, sorted, indices, size);
	return (1);
}

void	quicksort(long *array, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = partition(array, start, end);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, end);
}

int	partition(long *array, int start, int end)
{
	int	i;
	int	j;

	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] < array[end])
		{
			i++;
			ft_swap(array + i, array + j);
		}
		j++;
	}
	ft_swap(array + i + 1, array + end);
	return (i + 1);
}

void	normalize(long *unsorted, long *sorted, long *indices, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (sorted[i] == unsorted[j])
				indices[j] = i;
			i++;
		}
		j++;
	}
}

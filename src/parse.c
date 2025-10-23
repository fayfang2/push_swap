/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:29:48 by fayfang           #+#    #+#             */
/*   Updated: 2025/10/23 11:41:03 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse(size_t size, char **argv, long *indices)
{
	long	*unsorted;
	long	*sorted;
	size_t	i;

	i = 0;
	unsorted = init_array(size);
	sorted = init_array(size);
	while (i < size)
	{
		if (!check_format(argv[i + 1]) || !ft_strcmp(argv[i + 1], "-") || !ft_strcmp(argv[i + 1], "+"))
		{
			free_arrays(unsorted, sorted, indices);
			error_msg("Error\n", NULL, NULL, NULL);
		}
		unsorted[i] = ft_atol(argv[i + 1]);
		if (unsorted[i] < INT_MIN || unsorted[i] > INT_MAX)
		{
			free_arrays(unsorted, sorted, indices);
			error_msg("Error\n", NULL, NULL, NULL);
		}
		sorted[i] = unsorted[i];
		i++;
	}
	checks(unsorted, sorted, indices, size);
	free_arrays(unsorted, sorted, NULL);
}

void	checks(long *unsorted, long *sorted, long *indices, size_t size)
{
	if (check_sorted(unsorted, size))
	{
		free_arrays(unsorted, sorted, indices);
		error_msg("\n", NULL, NULL, NULL);
	}
	quicksort(sorted, 0, size - 1);
	if (check_dup(sorted, size))
	{
		free_arrays(unsorted, sorted, indices);
		error_msg("Error\n", NULL, NULL, NULL);
	}
	normalize(unsorted, sorted, indices, size);
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

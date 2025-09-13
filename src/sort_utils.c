/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:29:28 by fayfang           #+#    #+#             */
/*   Updated: 2025/08/18 15:56:45 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_reversed(t_queue *queue)
{
	size_t	i;
	size_t	current;
	size_t	next;

	i = 0;
	if (!queue || queue->size < 2)
		return (0);
	while (i + 1 < queue->size)
	{
		current = (queue->head + i) % (queue->max);
		next = (queue->head + i + 1) % (queue->max);
		if (queue->queue[current] < queue->queue[next])
			return (0);
		i++;
	}
	return (1);
}

size_t	find_index(t_queue *queue, long n)
{
	size_t	i;
	size_t	current;

	i = 0;
	while (i < queue->size)
	{
		current = (queue->head + i) % (queue->max);
		if (queue->queue[current] == n)
			return (i);
		i++;
	}
	return (queue->size);
}

long	find_max(t_queue *queue)
{
	long	max;
	long	current;
	size_t	i;

	i = 0;
	if (!queue || queue->size == 0)
		return (0);
	current = queue->head;
	max = queue->queue[current];
	while (i + 1 < queue->size)
	{
		current = (queue->head + i + 1) % (queue->max);
		if (max < queue->queue[current])
			max = queue->queue[current];
		i++;
	}
	return (max);
}

long	find_min(t_queue *queue)
{
	long	min;
	long	current;
	size_t	i;

	i = 0;
	if (!queue || queue->size  == 0)
		return (0);
	current = queue->head;
	min = queue->queue[current];
	while (i + 1 < queue->size)
	{
		current = (queue->head + i + 1) % (queue->max);
		if (min > queue->queue[current])
			min = queue->queue[current];
		i++;
	}
	return (min);
}
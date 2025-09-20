/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:27:06 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/20 16:58:36 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_queue(t_queue *queue, size_t max_size, long *indices, t_flag c)
{
	size_t	i;

	i = 0;
	queue->flag = c;
	queue->max = max_size;
	queue->size = 0;
	queue->queue = ft_calloc(max_size, sizeof(long));
	if (!(queue->queue))
		return (0);
	queue->head = 0;
	queue->tail = 0;
	while (i < max_size && indices != NULL)
		qadd_back(queue, indices[i++]);
	queue->other = NULL;
	return (1);
}

int	isfull(t_queue *queue)
{
	if (queue->size == queue->max)
		return (1);
	return (0);
}

int	isempty(t_queue *queue)
{
	if (queue->size == 0)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:14:43 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/11 19:33:00 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	qadd_back(t_queue *queue, long num)
{
	if (!queue)
		error_msg("Error: Queue is NULL.\n", queue, NULL, NULL);
	if (isFull(queue))
		error_msg("Error: Queue is full, overflow.\n", queue, NULL, NULL);
	queue->queue[queue->tail] = num;
	queue->tail = (queue->tail + 1) % (queue->max);
	queue->size++;
}

void	qadd_front(t_queue *queue, long num)
{
	if (isFull(queue))
		error_msg("Error: Queue is full, overflow.\n", queue, NULL, NULL);
	queue->head = (queue->head + queue->max - 1) % (queue->max);
	queue->queue[queue->head] = num;
	queue->size++;
}

long	qdel_back(t_queue *queue)
{
	long	del;

	if (isEmpty(queue))
		error_msg("Error: Queue is empty.\n", queue, NULL, NULL);
	queue->tail = (queue->tail + queue->max - 1) % (queue->max);
	del = queue->queue[queue->tail];
	queue->size--;
	return (del);
}

long	qdel_front(t_queue *queue)
{
	long	del;

	if (isEmpty(queue))
		error_msg("Error: Queue is empty.\n", queue, NULL, NULL);
	del = queue->queue[queue->head];
	queue->head = (queue->head + 1) % (queue->max);
	queue->size--;
	return (del);
}

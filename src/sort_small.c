/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:08:28 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/05 16:50:16 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_reversed(t_queue *queue, t_print *instr)
{
	t_queue *other;

	other = queue->other;
	while (queue->size > 3)
	{
		q_revrotate(queue, instr);
		q_push(queue, instr);
	}
	q_revrotate(queue, instr);
	q_swap(queue, instr);
	q_rotate(queue, instr);
	while (other->size > 0)
		q_push(other, instr);
}

void	sort_three(t_queue *queue, t_print *instr)
{
	long	max;
	size_t	next;
	
	max = find_max(queue);
	next = (queue->head + 1) % (queue->max);
	if (queue->queue[queue->head] == max)
		q_rotate(queue, instr);
	else if (queue->queue[next] == max)
		q_revrotate(queue, instr);
	next = (queue->head + 1) % (queue->max);
	if (queue->queue[queue->head] > queue->queue[next])
		q_swap(queue, instr);
}

void	sort_five(t_queue *queue, t_print *instr)
{
	size_t	i;
	size_t	n;
	size_t	min;
	t_queue	*other;

	i = 0;
	n = queue->size - 3;
	other = queue->other;
	while (i < n)
	{
		min = find_index(queue, find_min(queue));
		while (queue->queue[queue->head] != find_min(queue))
		{
			if (min > (queue->size / 2))
				q_revrotate(queue, instr);
			else
				q_rotate(queue, instr);
		}
		q_push(queue, instr);
		i++;
	}
	sort_three(queue, instr);
	while (other->size > 0)
		q_push(other, instr);
}

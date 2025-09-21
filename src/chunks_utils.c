/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:39:05 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/20 17:19:07 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_queue	*set_stack(t_chunk *chunk, t_queue *queue)
{
	t_queue	*stack;

	if (chunk->flag == queue->flag)
		stack = queue;
	else
		stack = queue->other;
	return (stack);
}

void	set_loc(t_chunk *chunk)
{
	if (!chunk->min)
		chunk->min = init_chunk();
	if (!chunk->mid)
		chunk->mid = init_chunk();
	if (!chunk->max)
		chunk->max = init_chunk();
	chunk->min->flag = b;
	chunk->mid->flag = a;
	if (chunk->flag == a)
		chunk->mid->flag = b;
	chunk->max->flag = a;
	chunk->min->loc = bottom;
	if (chunk->flag == b && chunk->loc == bottom)
		chunk->min->loc = top;
	chunk->mid->loc = bottom;
	if (chunk->flag == a)
		chunk->mid->loc = top;
	chunk->max->loc = top;
	if (chunk->flag == a && chunk->loc == top)
		chunk->max->loc = bottom;
}

void	set_pivots(t_chunk *chunk)
{
	long	div;

	div = chunk->size / 3;
	chunk->pivot1 = chunk->lower + div;
	chunk->pivot2 = chunk->lower + div * 2;
	chunk->min->lower = chunk->lower;
	chunk->mid->lower = chunk->pivot1;
	chunk->max->lower = chunk->pivot2;
}

void	set_head(t_chunk *chunk, t_queue *queue)
{
	t_queue	*stack;

	stack = set_stack(chunk, queue);
	if (chunk->loc == top)
		chunk->head = stack->head;
	else if (chunk->loc == bottom)
		chunk->head = stack->tail - 1;
}

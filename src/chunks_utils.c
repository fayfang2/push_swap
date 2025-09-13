/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:39:05 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/13 16:18:10 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_queue	*set_stack(t_chunk *chunk, t_queue *queue)
{
	t_queue	*stack;

	stack = (chunk->flag == queue->flag) ? queue : queue->other;
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
	chunk->mid->flag = (chunk->flag == a) ? b : a;
	chunk->max->flag = a;
	chunk->min->loc = (chunk->flag == b && chunk->loc == bottom) ? top : bottom;
	chunk->mid->loc = (chunk->flag == a) ? top : bottom;
	chunk->max->loc = (chunk->flag == a && chunk->loc == top) ? bottom : top;
}

void	set_pivots(t_chunk *chunk)
{
	long	div;
	long	mod;

	div = chunk->size / 3;
	mod = chunk->size % 3;
	chunk->pivot1 = chunk->lower + div;
	chunk->pivot2 = chunk->lower + div * 2;
	if (mod == 2)
	{
		chunk->pivot1 += 1;
		chunk->pivot2 += 2;
	}
	chunk->min->lower = chunk->lower;
	chunk->mid->lower = chunk->pivot1;
	chunk->max->lower = chunk->pivot2;
}

void	set_head(t_chunk *chunk, t_queue *queue)
{
	t_queue *stack;

	stack = (chunk->flag == queue->flag) ? queue : queue->other;
	if (chunk->loc == top)
		chunk->head = stack->head;
	else if (chunk->loc == bottom)
		chunk->head = stack->tail;
}
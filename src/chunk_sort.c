/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:39:51 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/13 16:09:24 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_chunks(t_queue *queue, t_print *instr)
{
	t_chunk	*chunk;
	t_queue	*stack_a;

	stack_a = (queue->flag == a) ? queue : queue-> other;
	chunk = init_chunk();
	chunk->flag = stack_a->flag;
	chunk->loc = top;
	chunk->size = stack_a->size;
	chunk->head = stack_a->head;
	sort_recursive(chunk, stack_a, instr);
	return ;
}

void sort_recursive(t_chunk *chunk, t_queue *queue, t_print *instr)
{
	t_queue	*stack;
	t_chunk	*dest;

	if (!chunk || chunk->size < 1)
		return ;
	stack = set_stack(chunk, queue);
	dest = init_chunk();
	dest->loc = top;
	dest->flag = a;
	chunk_totop(chunk, stack);
	if (chunk->size < 4)
	{
		while(chunk->size--)
			move(chunk, dest, stack, instr);
		return ;
	}
	split_chunks(chunk, stack, instr);
	sort_recursive(chunk->max, stack, instr);
	sort_recursive(chunk->mid, stack, instr);
	sort_recursive(chunk->min, stack, instr);
}

void	split_chunks(t_chunk *chunk, t_queue *queue, t_print *instr)
{
	long	nbr;
	t_queue	*stack;

	set_loc(chunk);
	set_pivots(chunk);
	stack = set_stack(chunk, queue);
	while (chunk->size--)
	{
		set_head(chunk, stack);
		nbr = stack->queue[chunk->head];
		printf("nbr to move: %ld\n", stack->queue[chunk->head]);
		if (nbr < chunk->pivot1)
			move(chunk, chunk->min, stack, instr);
		else if (nbr < chunk->pivot2)
			move(chunk, chunk->mid, stack, instr);
		else
			move(chunk, chunk->max, stack, instr);
	}
}
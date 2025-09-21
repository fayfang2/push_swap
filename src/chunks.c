/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 09:22:52 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/02 15:47:58 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_chunk *init_chunk(t_queue *queue)
{
	t_chunk *chunk;

	chunk = ft_calloc(sizeof(t_chunk), 1);
	if (!chunk)
		error_msg("Error: failed to initialise chunk.\n", NULL, NULL);
	chunk->flag = queue->flag;
	chunk->loc = top;
	chunk->size = queue->size;
	chunk->head = queue->queue[queue->head];
	chunk->pivot1 = 0;
	chunk->pivot2 = 0;
	return (chunk);
}

t_dest	*init_dest()
{
	t_dest	*loc;
	
	loc  = ft_calloc(sizeof(t_dest), 1);
	if (!loc)
		return (NULL);
	loc->min = ft_calloc(sizeof(t_chunk), 1);
	loc->mid = ft_calloc(sizeof(t_chunk), 1);
	loc->max = ft_calloc(sizeof(t_chunk), 1);
	if (!loc->min || !loc->mid || !loc->max)
		return (NULL);
	return (loc);
}

t_queue	*set_stack(t_flag c, t_queue *stack_a, t_queue *stack_b)
{
	if (c == a)
		return (stack_a);
	else if (c == b)
		return (stack_b);
	return (NULL);
}

void	set_pivots(t_chunk *chunk)
{
	long	big;
	long	diff;

	if (chunk->size < 1)
		return ;
	diff = chunk->size % 3;
/* 	printf("Chunk size is: %ld\n", chunk->size);
	printf("Div by 3 is: %ld\n", chunk->size / 3);
	printf("Mod by 3 is: %ld\n", chunk->size % 3); */
	chunk->pivot1 = chunk->size / 3 - 1;
	chunk->pivot2 = chunk->pivot1 + chunk->size / 3;
	if (diff == 2)
		chunk->pivot2 += 1;
	big = chunk->pivot2 + chunk->size / 3;
	if (diff == 1 || diff == 2)
		big += 1;
	printf("sml: %ld\n", chunk->pivot1);
	printf("med: %ld\n", chunk->pivot2);
	printf("big: %ld\n", big);
	return ;
}

void	set_loc(t_chunk *chunk, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->flag = b;
	min->loc = bottom;
	max->flag = a;
	max->loc = top;
	if (chunk->flag == a)
	{
		mid->flag = b;
		mid->loc = top;
		if (chunk->loc == top)
			chunk->loc = bottom;
	}
	else if (chunk->flag == b)
	{
		mid->flag = a;
		mid->loc = bottom;
		if (chunk->loc == bottom)
			chunk->loc = top;
	}
}

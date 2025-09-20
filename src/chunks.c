/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:39:07 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/20 17:00:26 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_chunk	*init_chunk(void)
{
	t_chunk	*chunk;

	chunk = ft_calloc(sizeof(t_chunk), 1);
	if (!chunk)
		return (NULL);
	chunk->size = 0;
	chunk->head = 0;
	chunk->lower = 0;
	chunk->pivot1 = 0;
	chunk->pivot2 = 0;
	chunk->min = NULL;
	chunk->mid = NULL;
	chunk->max = NULL;
	return (chunk);
}

void	chunk_totop(t_chunk *chunk, t_queue *queue)
{
	t_queue	*stack;

	stack = set_stack(chunk, queue);
	if (chunk->size == stack->size && chunk->loc == bottom)
		chunk->loc = top;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:39:51 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/22 16:04:20 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_chunks(t_queue *queue, t_print *instr)
{
	t_chunk	*chunk;
	t_queue	*stack_a;

	if (queue->flag == a)
		stack_a = queue;
	else
		stack_a = queue->other;
	chunk = init_chunk();
	chunk->flag = stack_a->flag;
	chunk->loc = top;
	chunk->size = stack_a->size;
	chunk->head = stack_a->head;
	sort_recursive(chunk, stack_a, instr);
	free_chunk(chunk);
}

void	sort_recursive(t_chunk *chunk, t_queue *queue, t_print *instr)
{
	t_queue	*stack;
	t_chunk	*dest;

	stack = set_stack(chunk, queue);
	dest = init_chunk();
	dest->loc = top;
	dest->flag = a;
	chunk_totop(chunk, stack);
	if (chunk->size < 5)
	{
		move_back(chunk, dest, stack, instr);
		free_chunk(dest);
		return ;
	}
	split_chunks(chunk, stack, instr);
	sort_recursive(chunk->max, stack, instr);
	sort_recursive(chunk->mid, stack, instr);
	sort_recursive(chunk->min, stack, instr);
	free_chunk(dest);
}

void	split_chunks(t_chunk *chunk, t_queue *queue, t_print *instr)
{
	long	nbr;
	t_queue	*stack;
	size_t	i;

	i = 0;
	set_loc(chunk);
	set_pivots(chunk);
	stack = set_stack(chunk, queue);
	while (i < chunk->size)
	{
		set_head(chunk, stack);
		nbr = stack->queue[chunk->head];
		if (nbr < chunk->pivot1)
			move(chunk, chunk->min, stack, instr);
		else if (nbr < chunk->pivot2)
			move(chunk, chunk->mid, stack, instr);
		else
			move(chunk, chunk->max, stack, instr);
		i++;
	}
}

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

void	print_instr(t_print *instr)
{
	size_t	i;

	i = 0;
	while (i < instr->count)
	{
		ft_printf("%s\n", instr->instructions[i]);
		i++;
	}
	return ;
}

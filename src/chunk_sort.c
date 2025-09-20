/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:39:51 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/20 17:01:56 by fayfang          ###   ########.fr       */
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

/* void	print_chunk(t_chunk *chunk, t_queue *queue)
{
	size_t	i;
	size_t	j;
	t_queue	*stack;
	long	*nbr;

	i = 0;
	j = 0;
	stack = set_stack(chunk, queue);
	set_head(chunk, stack);
	nbr = ft_calloc(sizeof(long), chunk->size);
	if (!nbr)
		return ;
	printf("Print unsorted:\t");
	while (i < chunk->size)
	{
		nbr[i] = stack->queue[(chunk->head + j) % stack->max];
		printf("%ld ", nbr[i]);
		i++;
		if (chunk->loc == top)
			j++;
		else if (chunk->loc == bottom)
			j--;
	}
	quicksort(nbr, 0, chunk->size - 1);
	i = 0;
	printf("\nPrint sorted:\t");
	while (i < chunk->size)
	{
		printf("%ld ", nbr[i]);
		i++;
	}
	printf("\n");
	free(nbr);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:39:51 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/15 07:50:31 by fayfang          ###   ########.fr       */
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
	free(chunk);
}

void sort_recursive(t_chunk *chunk, t_queue *queue, t_print *instr)
{
	t_queue	*stack;
	// t_queue	*stack_a;
	t_chunk	*dest;
	// long	*val;
	// size_t	size;
	
	if (!chunk || chunk->size < 1)
	{
		if (chunk)
			free_chunk(chunk);
		return ;
	}
	stack = set_stack(chunk, queue);
	// stack_a = (queue->flag == a) ? queue : queue->other;
	dest = init_chunk();
	dest->loc = top;
	dest->flag = a;
	chunk_totop(chunk, stack);
	if (chunk->size <= 4)
	{
		// while(chunk->size--)
		// {
		// 	move(chunk, dest, stack, instr);
		// 	sort_top(stack_a, 4, instr);
		// }
		// size = chunk->size + 4;
		// printf("chunk->size: %ld\n", chunk->size);
		// val = set_values(stack_a, size);
		// printf("values before move_back:\n");
		// print_values(val, size);
		move_back(chunk, dest, stack, instr);
		// val = set_values(stack_a, size);
		// printf("values after move_back:\n");
		// print_values(val, size);
		free(chunk);
		free(dest);
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
	size_t	i;

	i = 0;
	set_loc(chunk);
	set_pivots(chunk);
	stack = set_stack(chunk, queue);
	// print_chunk(chunk, stack);
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
/* 	if (chunk->min->size + chunk->mid->size + chunk->max->size != chunk->size)
		error_msg("Error: not updating sizes or moving values correctly.\n", queue, instr, chunk); */
/* 	printf("\nChunk max\n");
	printf("loc: %d, flag: %c, size: %ld\n", chunk->max->loc, chunk->max->flag, chunk->max->size);
	print_chunk(chunk->max, stack);
	printf("\nChunk mid\n");
	printf("loc: %d, flag: %c, size: %ld\n", chunk->mid->loc, chunk->mid->flag, chunk->mid->size);
	print_chunk(chunk->mid, stack);
	printf("\nChunk min\n");
	printf("loc: %d, flag: %c, size: %ld\n", chunk->min->loc, chunk->min->flag, chunk->min->size);
	print_chunk(chunk->min, stack);
	print_queues(stack);
	printf("\n\n"); */
}

void	print_chunk(t_chunk *chunk, t_queue *queue)
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
}

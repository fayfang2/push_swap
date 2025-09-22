/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 08:03:01 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/22 14:08:30 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void	print_queue(t_queue *queue)
{
	size_t	i;
	size_t	index;

	i = 0;
	while (i < queue->size)
	{
		index = (queue->head + i) % (queue->max);
		printf("Queue[%ld]: %ld\n", i, queue->queue[index]);
		i++;
	}
	return ;
} */

/* void	print_values(long *val, size_t	size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("val[%ld]: %ld\n", i, val[i]);
		i++;
	}
} */

/* void	print_queues(t_queue *queue)
{
	t_queue	*stack_a;
	t_queue	*stack_b;
	size_t	i;
	size_t	size;
	size_t	index_a;
	size_t	index_b;

	i = 0;

	stack_a = (queue->flag == a) ? queue : queue->other;
	stack_b = (queue->flag == b) ? queue : queue->other;
	size = (stack_a->size > stack_b->size) ? stack_a->size : stack_b->size;
	while (i < size)
	{
		printf("Queue[%ld]: ", i);
		if (i< stack_a->size)
		{
			index_a = (stack_a->head + i) % (stack_a->max);
			printf("%ld", stack_a->queue[index_a]);
		}
		else
			printf("NULL");
		printf("\t ");
		if (i < stack_b-> size)
		{
			index_b = (stack_b->head + i) % (stack_b->max);
			printf("%ld", stack_b->queue[index_b]);
		}
		else
			printf("NULL");
		printf("\n");
		i++;
	}
	printf("\tstack_a\tstack_b\n");
	return ;
} */

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 08:03:01 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/20 17:04:11 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
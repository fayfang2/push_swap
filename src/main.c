/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:54:40 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/02 14:03:55 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_print	*instr;
	t_queue	*stack_a;
	t_queue	*stack_b;
	size_t	size;

	size = argc - 1;
	if (size < 1)
		error_msg("Error: not enough arguments.\n", NULL, NULL);
	stack_a = init_stack(size, argv, a);
	stack_b = init_stack(size, argv, b);
	instr = init_instr(size);
	if (check_reversed(stack_a))
		sort_reversed(stack_a, stack_b, instr);
	else if (stack_a->size == 3)
		sort_three(stack_a, instr);
	else if (stack_a->size < 6)
		sort_five(stack_a, stack_b, instr);
	else
		sort_chunks(stack_a, stack_b, instr);
	// print_queues(stack_a, stack_b);
	print_instr(instr);
	free_stack(stack_a);
	free_stack(stack_b);
	free_instr(instr);
	return (0);
}

t_queue	*init_stack(size_t size, char **argv, t_flag c)
{
	t_queue	*stack;
	long	indices[size];

	stack = ft_calloc(sizeof(t_queue), 1);
	if (!stack)
		error_msg("Error: failed to allocate memory.\n", stack, NULL);
	if (c == a)
	{
		parse(size, argv, indices);
		init_queue(stack, size, indices, c);
	}
	else if (c == b)
		init_queue(stack, size, NULL, c);
	return (stack);	
}

void	print_queue(t_queue *queue)
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
}

void	print_queues(t_queue *queue_a, t_queue *queue_b)
{
	size_t	i;
	size_t	size;
	size_t	index_a;
	size_t	index_b;

	i = 0;
	size = (queue_a->size > queue_b->size) ? queue_a->size : queue_b->size;
	while (i < size)
	{
		printf("Queue[%ld]: ", i);
		if (i< queue_a->size)
		{
			index_a = (queue_a->head + i) % (queue_a->max);
			printf("%ld", queue_a->queue[index_a]);
		}
		else
			printf("NULL");
		printf("\t ");
		if (i < queue_b-> size)
		{
			index_b = (queue_b->head + i) % (queue_b->max);
			printf("%ld", queue_b->queue[index_b]);
		}
		else
			printf("NULL");
		printf("\n");
		i++;
	}
	printf("\tstack_a\tstack_b\n");
	return ;
}


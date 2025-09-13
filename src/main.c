/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:54:40 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/12 07:43:37 by fayfang          ###   ########.fr       */
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
		error_msg("Error: not enough arguments.\n", NULL, NULL, NULL);
	stack_a = init_stack(size, argv, a);
	stack_b = init_stack(size, argv, b);
	stack_a->other = stack_b;
	stack_b->other = stack_a;
	instr = init_instr(size);
	if (check_reversed(stack_a))
		sort_reversed(stack_a, instr);
	else if (stack_a->size == 3)
		sort_three(stack_a, instr);
	else if (stack_a->size < 6)
		sort_five(stack_a, instr);
	else
		sort_chunks(stack_a, instr);
	print_queues(stack_a);
	print_instr(instr);
	free_stack(stack_a);
	free_instr(instr);
	return (0);
}

t_queue	*init_stack(size_t size, char **argv, t_flag c)
{
	t_queue	*stack;
	long	indices[size];

	stack = ft_calloc(sizeof(t_queue), 1);
	if (!stack)
		error_msg("Error: failed to allocate memory.\n", stack, NULL, NULL);
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

void	print_queues(t_queue *queue)
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
}


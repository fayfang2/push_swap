/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:54:40 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/21 08:55:45 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_print	*instr;
	t_queue	*stack_a;
	t_queue	*stack_b;
	size_t	size;

	size = argc - 1;
	if (size < 1)
		error_msg("Error\n", NULL, NULL, NULL);
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
	final_check(stack_a);
	print_instr(instr);
	free_stack(stack_a);
	free_instr(instr);
}

t_queue	*init_stack(size_t size, char **argv, t_flag c)
{
	t_queue	*stack;
	long	*indices;

	stack = ft_calloc(sizeof(t_queue), 1);
	if (!stack)
		error_msg("Error\n", stack, NULL, NULL);
	indices = init_array(size);
	if (c == a)
	{
		parse(size, argv, indices);
		init_queue(stack, size, indices, c);
	}
	else if (c == b)
		init_queue(stack, size, NULL, c);
	free(indices);
	return (stack);
}

long	*init_array(size_t size)
{
	long	*array;

	array = ft_calloc(sizeof(long), size);
	if (!array)
		error_msg("Error\n", NULL, NULL, NULL);
	return (array);
}

void	final_check(t_queue *queue)
{
	size_t	i;
	long	nbr;

	i = 0;
	while (i < queue->size)
	{
		nbr = queue->queue[(queue->head + i) % queue->max];
		if (nbr != (long)i)
			error_msg("Error\n", queue, NULL, NULL);
		i++;
	}
}

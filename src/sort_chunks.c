/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:32:26 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/04 13:11:18 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_chunks(t_queue *stack_a, t_queue *stack_b, t_print *instr)
{
	t_chunk	*biggest;
	t_queue	*stack;
	size_t	i;

	i = 0;
	biggest = init_chunk(stack_a);
	split_chunks(biggest, stack_a, stack_b, instr);
	(void) i;
	(void) instr;
	(void) stack;
	return ;
}

void	split_chunks(t_chunk *chunk, t_queue *stack_a, t_queue *stack_b, t_print *instr)
{
	t_queue	*stack;
	t_queue	*dest;
	t_dest	*loc;
	long	nbr;
	size_t	i;
	
	i = 0;
	stack = set_stack(chunk->flag, stack_a, stack_b);
	dest = (chunk->flag == a) ? stack_b : stack_a;
	set_pivots(chunk);
	loc = init_dest();
	set_loc(chunk, loc->min, loc->mid, loc->max);
	while (i < chunk->size)
	{
		nbr = stack->queue[(stack->head + i) % stack->max];
		if (nbr <= chunk->pivot1)
			move(stack, dest, loc->min, instr);
		else if (nbr <= chunk->pivot2)
			move(stack, dest, loc->mid, instr);
		else 
			move(stack, dest, loc->max, instr);
		i++;
	}
}

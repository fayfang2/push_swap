/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:08:28 by fayfang           #+#    #+#             */
/*   Updated: 2025/08/26 16:15:51 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_reversed(t_queue *stack_a, t_queue	*stack_b, t_print *instr)
{
	while (stack_a->size > 3)
	{
		q_revrotate(stack_a, instr);
		q_push(stack_a, stack_b, instr);
	}
	q_revrotate(stack_a, instr);
	q_swap(stack_a, instr);
	q_rotate(stack_a, instr);
	while (stack_b->size > 0)
		q_push(stack_b, stack_a, instr);
}

void	sort_three(t_queue *queue, t_print *instr)
{
	long	max;
	size_t	next;
	
	max = find_max(queue);
	next = (queue->head + 1) % (queue->max);
	if (queue->queue[queue->head] == max)
		q_rotate(queue, instr);
	else if (queue->queue[next] == max)
		q_revrotate(queue, instr);
	next = (queue->head + 1) % (queue->max);
	if (queue->queue[queue->head] > queue->queue[next])
		q_swap(queue, instr);
}

void	sort_five(t_queue *stack_a, t_queue *stack_b, t_print *instr)
{
	size_t	i;
	size_t	n;
	size_t	min_ind;
	long	min;

	i = 0;
	n = stack_a->size - 3;
	while (i < n)
	{
		min = find_min(stack_a);
		min_ind = find_index(stack_a, min);
		while (stack_a->queue[stack_a->head] != min)
		{
			if (min_ind > (stack_a->size / 2))
				q_revrotate(stack_a, instr);
			else
				q_rotate(stack_a, instr);
		}
		q_push(stack_a, stack_b, instr);
		i++;
	}
	sort_three(stack_a, instr);
	while (stack_b->size > 0)
		q_push(stack_b, stack_a, instr);
}

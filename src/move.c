/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:16:57 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/20 17:41:15 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move(t_chunk *src, t_chunk *dest, t_queue *queue, t_print *instr)
{
	t_queue	*stack;
	t_queue	*other;

	stack = set_stack(src, queue);
	other = stack->other;
	if (src->flag == dest->flag && src->loc == dest->loc)
	{
		dest->size++;
		return ;
	}
	if (src->loc == bottom && (dest->loc == top || (dest->flag != src->flag)))
		q_revrotate(stack, instr);
	if (src->flag != dest->flag)
	{
		q_push(stack, instr);
		if (dest->loc == bottom)
			q_rotate(other, instr);
	}
	if ((src->loc == top && dest->loc == bottom) && (src->flag == dest->flag))
		q_rotate(stack, instr);
	dest->size++;
}

void	move_back(t_chunk *src, t_chunk *dest, t_queue *queue, t_print *instr)
{
	t_queue	*stack;
	size_t	max;
	size_t	i;

	max = 4;
	if (queue->size < 4)
		max = queue->size;
	stack = set_stack(dest, queue);
	i = 0;
	if (src->flag == dest->flag && src->loc == dest->loc)
	{
		sort_top(stack, src->size, max, instr);
		return ;
	}
	while (i < src->size)
	{
		move(src, dest, queue, instr);
		i++;
	}
	sort_top(stack, src->size, max, instr);
}

void	sort_two(t_queue *queue, t_print *instr)
{
	long	first;
	long	second;

	first = queue->queue[queue->head];
	second = queue->queue[(queue->head + 1) % queue->max];
	if ((queue->flag == a && first > second)
		|| (queue->flag == b && first < second))
		q_swap(queue, instr);
}

void	sort_top(t_queue *queue, size_t size, size_t max, t_print *instr)
{
	long	*val;

	val = init_array(max);
	set_values(queue, val, max);
	if (check_sorted(val, max))
		return (free(val));
	sort_two(queue, instr);
	set_values(queue, val, max);
	if (check_sorted(val, max))
		return (free(val));
	q_push(queue, instr);
	sort_two(queue, instr);
	set_values(queue, val, max);
	if (!(val[2] > val[1]) && size > 3)
	{
		q_push(queue, instr);
		q_swap(queue, instr);
		sort_two(queue->other, instr);
		q_push(queue->other, instr);
		sort_two(queue, instr);
	}
	q_push(queue->other, instr);
	sort_two(queue, instr);
	free(val);
}

void	set_values(t_queue *queue, long *val, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && i < queue->size)
	{
		val[i] = queue->queue[(queue->head + i) % queue->max];
		i++;
	}
}

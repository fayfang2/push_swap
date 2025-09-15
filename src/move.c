/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:16:57 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/15 07:16:47 by fayfang          ###   ########.fr       */
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
	size_t	i;

	stack = set_stack(dest, queue);
	i = 0;
	if (src->flag == dest->flag && src->loc == dest->loc)
	{
		sort_top(stack, src->size, instr);
		return ;
	}
	while (i < src->size)
	{
		move(src, dest, queue, instr);
		i++;
	}
	sort_top(stack,  src->size, instr);

}

void	sort_two(t_queue *queue, t_print *instr)
{
	long	*val;
	size_t	size;

	size = 2;
	val = set_values(queue, size);
	if ((queue->flag == a && val[0] > val[1]) || 
		(queue->flag == b && val[0] < val[1]))
		q_swap(queue, instr);
	free(val);
}

void	sort_top(t_queue *queue, size_t size, t_print *instr)
{
	long	*val;
	size_t	max;

	max = (queue->size < 4) ? queue->size : 4;
	val = set_values(queue, max);
	if (check_sorted(val, max))
		return (free(val));
	sort_two(queue, instr);
	val = set_values(queue, max);
	if (check_sorted(val, max))
		return (free(val));
	q_push(queue, instr);
	sort_two(queue, instr);
	val = set_values(queue, max);
	if (!(val[2] > val[1]) && size > 3)
	{
		q_push(queue, instr);
		sort_two(queue, instr);
		sort_two(queue->other, instr);
		q_push(queue->other, instr);
		sort_two(queue, instr);
	}
	q_push(queue->other, instr);
	sort_two(queue, instr);
	free(val);
}

long	*set_values(t_queue *queue, size_t size)
{
	long	*val;
	size_t	i;

	i = 0;
	val = ft_calloc(sizeof(long), size);
	if (!val)
		return (NULL);
	while (i < size && i < queue->size)
	{
		val[i] = queue->queue[(queue->head + i) % queue->max];
		i++;
	}
	return (val);
}

void	print_values(long *val, size_t	size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("val[%ld]: %ld\n", i, val[i]);
		i++;
	}
}
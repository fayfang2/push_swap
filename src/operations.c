/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:23:12 by fayfang           #+#    #+#             */
/*   Updated: 2025/08/26 16:14:07 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	q_swap(t_queue *queue, t_print *instr)
{
	long	first;
	long	second;

	if (queue->size < 2)
		return ;
	first = queue->head;
	second = (queue-> head + 1) % (queue->max);
	ft_swap(queue->queue + first, queue->queue + second);
	if (queue->flag == a)
		add_instr(instr, instr->operations[sa]);
	else if (queue->flag == b)
		add_instr(instr, instr->operations[sb]);
	return ;
}

void	q_push(t_queue *src, t_queue *dest, t_print *instr)
{
	long	temp;

	if (src->size < 1)
		return ;
	temp = qdel_front(src);
	qadd_front(dest, temp);
	if (dest->flag == a)
		add_instr(instr, instr->operations[pa]);
	else if (dest->flag == b)
		add_instr(instr, instr->operations[pb]);
	return ;
}

void	q_rotate(t_queue *queue, t_print *instr)
{
	long	temp;

	if (queue->size < 2)
		return ;
	temp = qdel_front(queue);
	qadd_back(queue, temp);
	if (queue->flag == a)
		add_instr(instr, instr->operations[ra]);
	else if (queue->flag == b)
		add_instr(instr, instr->operations[rb]);
	return ;
}

void q_revrotate(t_queue *queue, t_print *instr)
{
	long	temp;

	if (queue->size < 2)
		return ;
	temp = qdel_back(queue);
	qadd_front(queue, temp);
	if (queue->flag == a)
		add_instr(instr, instr->operations[rra]);
	else if (queue->flag == b)
		add_instr(instr, instr->operations[rrb]);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:16:57 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/13 16:30:21 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move(t_chunk *src, t_chunk *dest, t_queue *queue, t_print *instr)
{
	t_queue	*other;

	other = queue->other;
	if (src->flag == dest->flag && src->loc == dest->loc)
		return ;
	if (src->loc == bottom && (dest->loc == top || (dest->flag != src->flag)))
		q_revrotate(queue, instr);
	if (src->flag != dest->flag)
	{
		q_push(queue, instr);
		if (dest->loc == bottom)
			q_rotate(other, instr);
	}
	if ((src->loc == top && dest->loc == bottom) && (src->flag == dest->flag))
		q_rotate(queue, instr);
	dest->size++;
}
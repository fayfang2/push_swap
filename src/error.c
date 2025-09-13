/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:18:11 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/11 19:30:18 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_msg(char *msg, t_queue *stack, t_print *instr, t_chunk *chunk)
{
	if (stack)
		free_stack(stack);
	if (instr)
		free_instr(instr);
	if (chunk)
		free_chunk(chunk);
	if (msg)
		ft_putstr_fd(msg, 2);
	exit (1);
}

void	free_stack(t_queue *stack)
{
	if (stack->queue)
		free(stack->queue);
	if (stack->other)
	{
		if (stack->other->queue)
			free(stack->other->queue);
		free(stack->other);
	}
	free(stack);
}

void	free_instr(t_print	*instr)
{
	if (!instr)
		return ;
	if (instr->instructions)
		free(instr->instructions);
	if (instr->operations)
		free(instr->operations);
	free(instr);
}

void	free_chunk(t_chunk *chunk)
{
	if (chunk->min)
		free(chunk->min);
	if (chunk->mid)
		free(chunk->mid);
	if (chunk->max)
		free(chunk->max);
	free(chunk);
}


/* void	error_msg(char *msg, size_t count, ...)
{
	va_list	arg;
	t_queue	*stack;
	size_t	i;

	va_start(arg, count);
	i = 0;
	while (i < count)
	{
		stack = va_arg(arg, t_queue*);
		if (stack)
		{
			if (stack->queue)
				free(stack->queue);
			free(stack);
		}
		i++;
	}
	va_end(arg);
	if (msg)
		ft_putstr_fd(msg, 2);
	exit (1);
} */
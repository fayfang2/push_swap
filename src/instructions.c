/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:43:32 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/15 07:37:31 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_print	*init_instr(size_t size)
{
	t_print *instr;

	instr = ft_calloc(sizeof(t_print), 1);
	if (!instr)
		error_msg("Error: failed to allocate memory for instr.\n", NULL, instr, NULL);
	instr->count = 0;
	if (size <= 5)
		instr->size = 16;
	else if (size <= 100)
		instr->size = 1300;
	else if (size <= 500)
		instr->size = 5500;
	else
		instr->size = 10000;
	instr->instructions = ft_calloc(instr->size, sizeof(char *));
	if (!init_ops(instr))
		error_msg("Error: failed to initiate ops.\n", NULL, instr, NULL);
	if (!instr->instructions)
		error_msg("Error: failed to initiate instr.\n", NULL, instr, NULL);
	return (instr);
}
int init_ops(t_print *instr)
{
	instr->operations = ft_calloc(ops_count, sizeof(char *));
	if (!instr->operations)
			error_msg("Error: failed to initiate instr.\n", NULL, instr, NULL);
		instr->operations[sa] = "sa";
		instr->operations[sb] = "sb";
		instr->operations[ss] = "ss";
		instr->operations[pa] = "pa";
		instr->operations[pb] = "pb";
		instr->operations[ra] = "ra";
		instr->operations[rb] = "rb";
		instr->operations[rr] = "rr";
		instr->operations[rra] = "rra";
		instr->operations[rrb] = "rrb";
		instr->operations[rrr] = "rrr";
	return (1);
}
void	add_instr(t_print *instr, char *operation)
{
	// char	*prev;
	if (!instr || !operation)
		return ;
	// prev = instr->instructions[instr->count - 1];
	instr->instructions[instr->count] = operation;
	instr->count++;
	if (instr->count > instr->size)
	{
		print_instr (instr);
		error_msg("Error: exceeding instr limit or entering infinite recursion.\n", NULL, instr, NULL);
	}
}

void	print_instr(t_print *instr)
{
	size_t	i;

	i = 0;
	while (i < instr->count)
	{
		ft_printf("%s\n", instr->instructions[i]);
		i++;
	}
	printf("Instructions: %ld\n", instr->count);
	return ;
}
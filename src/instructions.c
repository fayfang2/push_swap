/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:43:32 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/21 08:57:32 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_print	*init_instr(size_t size)
{
	t_print	*instr;

	instr = ft_calloc(sizeof(t_print), 1);
	if (!instr)
		error_msg("Error: failed to allocate memory.\n", NULL, instr, NULL);
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
	if (!instr->instructions)
		error_msg("Error\n", NULL, instr, NULL);
	if (!init_ops(instr))
		error_msg("Error\n", NULL, instr, NULL);
	return (instr);
}

int	init_ops(t_print *instr)
{
	instr->operations = ft_calloc(ops_count, sizeof(char *));
	if (!instr->operations)
		error_msg("Error.\n", NULL, instr, NULL);
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
	if (!instr || !operation)
		return ;
	if (instr->count > 0 && check_case(instr, operation))
	{
		if (check_case(instr, operation) == 1)
			instr->instructions[instr->count - 1] = instr->operations[ss];
		else if (check_case(instr, operation) == 2)
			instr->instructions[instr->count - 1] = instr->operations[rr];
		else if (check_case(instr, operation) == 3)
			instr->instructions[instr->count - 1] = instr->operations[rrr];
		else if (check_case(instr, operation) == 4)
			instr->count--;
		return ;
	}
	instr->instructions[instr->count] = operation;
	instr->count++;
	if (instr->count > instr->size)
	{
		print_instr (instr);
		error_msg("Error\n", NULL, instr, NULL);
	}
}

int	check_case(t_print *instr, char *operation)
{
	char	*prev;
	char	*cur;

	if (!instr || !operation)
		return (0);
	cur = operation;
	if (instr->count > 0)
	{
		prev = instr->instructions[instr->count - 1];
		if ((!ft_strcmp(prev, "sa") && !ft_strcmp(cur, "sb"))
			|| (!ft_strcmp(prev, "sb") && !ft_strcmp(cur, "sa")))
			return (1);
		else if ((!ft_strcmp(prev, "ra") && !ft_strcmp(cur, "rb"))
			|| (!ft_strcmp(prev, "rb") && !ft_strcmp(cur, "ra")))
			return (2);
		else if ((!ft_strcmp(prev, "rra") && !ft_strcmp(cur, "rrb"))
			|| (!ft_strcmp(prev, "rrb") && !ft_strcmp(cur, "rra")))
			return (3);
		else if ((!ft_strcmp(prev, "pa") && !ft_strcmp(cur, "pb"))
			|| (!ft_strcmp(prev, "pb") && !ft_strcmp(cur, "pa")))
			return (4);
		else
			return (0);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

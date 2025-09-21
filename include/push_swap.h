/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:26:44 by fayfang           #+#    #+#             */
/*   Updated: 2025/09/04 15:03:53 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

# include "../libft/include/libft.h"

typedef enum e_flag
{
	a = 'a',
	b = 'b'
} t_flag;

typedef enum e_loc
{
	top,
	bottom
} t_loc;

typedef enum e_ops
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	ops_count
} t_ops;

typedef struct	s_chunk
{
	t_flag	flag;
	t_loc	loc;
	size_t	size;
	long	head;
	long	pivot1;
	long	pivot2;
} t_chunk;

typedef struct s_dest
{
	t_chunk	*current;
	t_chunk	*min;
	t_chunk	*mid;
	t_chunk *max;
} t_dest;

typedef struct s_print
{
	char	**instructions;
	char	**operations;
	size_t	size;
	size_t	count;
} t_print;

typedef struct	s_queue
{
	t_flag	flag;
	size_t	max;
	size_t	size;
	long	*queue;
	long	head;
	long	tail;
} t_queue;

//Parsing input and converting to array

void	parse(size_t size, char **argv, long *array);
void	quicksort(long *array, int start, int end);
int		partition(long *array, int start, int end);
void	normalize(long *unsorted, long *sorted, long *indices, size_t size);

void	ft_swap(long *a, long *b);
long	ft_atol(const char *s);
int		check_format(char *input);
int		check_sorted(long *array, size_t size);
int		check_dup(long *array, size_t size);

// Initialising stacks and instructions
t_queue	*init_stack(size_t size, char **argv, t_flag c);
int		init_queue(t_queue *queue, size_t max_size, long *indices, t_flag c);
t_print	*init_instr(size_t size);
int		init_ops(t_print *instr);

// Deque operations using circular buffer aray
int		isFull(t_queue *queue);
int		isEmpty(t_queue *queue);
void	qadd_back(t_queue *queue, long num);
void	qadd_front(t_queue *queue, long num);
long	qdel_back(t_queue *queue);
long	qdel_front(t_queue *queue);

// Push_swap operations
void	q_swap(t_queue *queue, t_print *instr);
void	q_push(t_queue *src, t_queue *dest, t_print *instr);
void	q_rotate(t_queue *queue, t_print *instr);
void	q_revrotate(t_queue *queue, t_print *instr);

// Sorting
int		check_reversed(t_queue *queue);
void	sort_reversed(t_queue *stack_a, t_queue *stack_b, t_print *instr);
void	sort_three(t_queue *queue, t_print *instr);
void	sort_five(t_queue *stack_a, t_queue *stack_b, t_print *instr);

// Utils
size_t	find_index(t_queue *queue, long n);
long	find_max(t_queue *queue);
long	find_min(t_queue *queue);

// Chunks
void	sort_chunks(t_queue *stack_a, t_queue *stack_b, t_print *instr);
t_chunk	*init_chunk(t_queue *queue);
t_dest	*init_dest();
void	set_pivots(t_chunk *chunk);
t_queue	*set_stack(t_flag c, t_queue *stack_a, t_queue *stack_b);
void	set_loc(t_chunk *chunk, t_chunk *min, t_chunk *mid, t_chunk *max);
void	split_chunks(t_chunk *chunk, t_queue *stack_a, t_queue *stackb, t_print *instr);

// Move
void	move(t_queue *src, t_queue *dest, t_chunk *loc, t_print *instr);

// Errors & freeing
void	error_msg(char *msg, t_queue *stack, t_print *instr);
void	free_stack(t_queue *stack);
void	free_instr(t_print *instr);

// Printing
void	add_instr(t_print *instr, char *operation);
void	print_instr(t_print *instr);

// Extras
void	print_queue(t_queue *queue);
void	print_queues(t_queue *queue_a, t_queue *queue_b);


#endif
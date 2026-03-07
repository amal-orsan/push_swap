/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort_using_selection_logic.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:43:30 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:54:40 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	selection_chunk(t_chunk *chunk)
{
	t_node	*target;
	int		pos;

	while (1)
	{
		target = (*chunk->a)->head;
		while (target && !(target->index >= chunk->min_idx
				&& target->index <= chunk->max_idx))
			target = target->next;
		if (!target)
			break ;
		pos = get_position(*chunk->a, target);
		if (pos <= (*chunk->a)->size / 2)
			while ((*chunk->a)->head != target)
				ra(&(*chunk->a), chunk->bench);
		else
			while ((*chunk->a)->head != target)
				rra(&(*chunk->a), chunk->bench);
		pb(&(*chunk->a), &(*chunk->b), chunk->bench);
	}
}

static void	ele_in_selection(t_chunk *chunk, int min_idx,
				int chunk_size, int len)
{
	int	max_idx;

	max_idx = min_idx + chunk_size - 1;
	if (max_idx >= len)
		max_idx = len - 1;
	chunk->max_idx = max_idx;
	chunk->min_idx = min_idx;
	selection_chunk(chunk);
}

static t_node	*find_max_index(t_stack *stack)
{
	t_node	*cur;
	t_node	*max_node;
	int		max;

	if (!stack || !stack->head)
		return (NULL);
	max = stack->head->index;
	max_node = stack->head;
	cur = stack->head;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_node = cur;
		}
		cur = cur->next;
	}
	return (max_node);
}

static void	push_back_to_a(t_chunk *chunk)
{
	t_node	*max;
	int		pos;

	while ((*chunk->b)->size > 0)
	{
		max = find_max_index(*chunk->b);
		pos = get_position(*chunk->b, max);
		if (pos <= (*chunk->b)->size / 2)
			while ((*chunk->b)->head != max)
				rb(&(*chunk->b), chunk->bench);
		else
			while ((*chunk->b)->head != max)
				rrb(&(*chunk->b), chunk->bench);
		pa(&(*chunk->a), &(*chunk->b), chunk->bench);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, int chunk_count, t_bench *bench)
{
	t_chunk		c;
	int			len;
	int			chunk_size;
	int			chunk;

	len = stack_len(*a);
	chunk_size = len / chunk_count + 1;
	chunk = 0;
	c.a = a;
	c.b = b;
	c.bench = bench;
	c.min_idx = 0;
	while (chunk < chunk_count)
	{
		ele_in_selection(&c, c.min_idx, chunk_size, len);
		c.min_idx += chunk_size;
		chunk++;
	}
	push_back_to_a(&c);
}

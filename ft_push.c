/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:41:32 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:41:37 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!src || !dst || src->size == 0)
		return ;
	node = src->head;
	src->head = node->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	node->next = dst->head;
	node->prev = NULL;
	if (dst->head)
		dst->head->prev = node;
	else
		dst->tail = node;
	dst->head = node;
	dst->size++;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push(*a, *b);
	write(1, "pa\n", 3);
	bench_count(bench, 'a');
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push(*b, *a);
	write(1, "pb\n", 3);
	bench_count(bench, 'b');
}

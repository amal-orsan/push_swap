/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:41:49 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:42:22 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rev_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	last->prev = NULL;
	last->next = stack->head;
	stack->head->prev = last;
	stack->head = last;
}

void	rra(t_stack **a, t_bench *bench)
{
	if (!a || !*a || (*a)->size < 2)
		return ;
	rev_rotate(*a);
	write(1, "rra\n", 4);
	bench_count(bench, 'c');
}

void	rrb(t_stack **b, t_bench *bench)
{
	if (!b || !*b || (*b)->size < 2)
		return ;
	rev_rotate(*b);
	write(1, "rrb\n", 4);
	bench_count(bench, 'd');
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	rev_rotate(*a);
	rev_rotate(*b);
	write(1, "rrr\n", 4);
	bench_count(bench, 'e');
}

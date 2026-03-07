/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:42:48 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:42:51 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rotate(t_stack **x)
{
	t_node	*old_head;
	t_node	*old_tail;

	if (!(*x) || (*x)->size < 2)
		return ;
	old_head = (*x)->head;
	old_tail = (*x)->tail;
	(*x)->head = old_head->next;
	(*x)->head->prev = NULL;
	old_tail->next = old_head;
	old_head->prev = old_tail;
	old_head->next = NULL;
	(*x)->tail = old_head;
}

void	ra(t_stack **a, t_bench *bench)
{
	if (!(*a) || (*a)->size < 2)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
	bench_count(bench, 'i');
}

void	rb(t_stack **b, t_bench *bench)
{
	if (!(*b) || (*b)->size < 2)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
	bench_count(bench, 'j');
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((*a) && (*a)->size >= 2)
		rotate(a);
	if ((*b) && (*b)->size >= 2)
		rotate(b);
	write(1, "rr\n", 3);
	bench_count(bench, 'k');
}

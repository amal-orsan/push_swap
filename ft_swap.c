/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:39:56 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:40:00 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_stack **a, t_bench *bench)
{
	int	tmp_val;
	int	tmp_idx;

	if (!a || !*a || (*a)->size < 2)
		return ;
	tmp_val = (*a)->head->value;
	tmp_idx = (*a)->head->index;
	(*a)->head->value = (*a)->head->next->value;
	(*a)->head->index = (*a)->head->next->index;
	(*a)->head->next->value = tmp_val;
	(*a)->head->next->index = tmp_idx;
	write(1, "sa\n", 3);
	bench_count(bench, 'f');
}

void	sb(t_stack **b, t_bench *bench)
{
	int	tmp_val;
	int	tmp_idx;

	if (!b || !*b || (*b)->size < 2)
		return ;
	tmp_val = (*b)->head->value;
	tmp_idx = (*b)->head->index;
	(*b)->head->value = (*b)->head->next->value;
	(*b)->head->index = (*b)->head->next->index;
	(*b)->head->next->value = tmp_val;
	(*b)->head->next->index = tmp_idx;
	write(1, "sb\n", 3);
	bench_count(bench, 'g');
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	int	tmp_val;
	int	tmp_idx;

	if (*a && (*a)->size >= 2)
	{
		tmp_val = (*a)->head->value;
		tmp_idx = (*a)->head->index;
		(*a)->head->value = (*a)->head->next->value;
		(*a)->head->index = (*a)->head->next->index;
		(*a)->head->next->value = tmp_val;
		(*a)->head->next->index = tmp_idx;
	}
	if (*b && (*b)->size >= 2)
	{
		tmp_val = (*b)->head->value;
		tmp_idx = (*b)->head->index;
		(*b)->head->value = (*b)->head->next->value;
		(*b)->head->index = (*b)->head->next->index;
		(*b)->head->next->value = tmp_val;
		(*b)->head->next->index = tmp_idx;
	}
	write(1, "ss\n", 3);
	bench_count(bench, 'h');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:41:02 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:41:04 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	int		pos;
	int		min_pos;
	t_node	*cur;
	int		min_value;

	pos = 0;
	min_pos = 0;
	cur = a->head;
	min_value = cur->value;
	while (cur)
	{
		if (cur->value < min_value)
		{
			min_value = cur->value;
			min_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (min_pos);
}

static void	rotate_min_to_top(t_stack **a, t_bench *bench, int min_pos)
{
	int	size;
	int	r;

	size = (*a)->size;
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, bench);
	}
	else
	{
		r = size - min_pos;
		while (r-- > 0)
			rra(a, bench);
	}
}

void	sort_four(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min_pos;
	int	pucount;

	pucount = (*a)->size - 3;
	if (!a || is_sorted(a))
		return ;
	while (pucount-- > 0)
	{
		min_pos = find_min_pos(*a);
		if (min_pos == 1)
			ra(a, bench);
		else if (min_pos == 2)
		{
			ra(a, bench);
			ra(a, bench);
		}
		else if (min_pos != 0)
			rra(a, bench);
		pb(a, b, bench);
	}
	sort_three(a, bench);
	while ((*b)->size > 0)
		pa(a, b, bench);
}

void	sort_five(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min_pos;
	int	pucount;

	pucount = 0;
	if (!a || is_sorted(a))
		return ;
	while (pucount++ < 2)
	{
		min_pos = find_min_pos(*a);
		rotate_min_to_top(a, bench, min_pos);
		pb(a, b, bench);
	}
	sort_three(a, bench);
	while ((*b)->size > 0)
		pa(a, b, bench);
}

int	is_sorted(t_stack **a)
{
	t_node	*cur;

	if (!a || !(*a) || !(*a)->head || (*a)->size < 2)
		return (1);
	cur = (*a)->head;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:40:50 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:40:53 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_two(t_stack **a, t_bench *bench)
{
	if (is_sorted(a))
		return ;
	if ((*a)->size == 2)
		sa(a, bench);
}

static void	sort_three_cases(t_stack **a, t_bench *bench, t_num n)
{
	if (n.first > n.second && n.second > n.third && n.first > n.third)
	{
		ra(a, bench);
		sa(a, bench);
	}
	else if (n.first > n.second && n.second < n.third && n.first > n.third)
		ra(a, bench);
	else if (n.first < n.second && n.second > n.third && n.third > n.first)
	{
		rra(a, bench);
		sa(a, bench);
	}
	else if (n.first > n.second && n.second < n.third && n.third > n.first)
		sa(a, bench);
	else if (n.first < n.second && n.second > n.third && n.third < n.first)
		rra(a, bench);
}

void	sort_three(t_stack **a, t_bench *bench)
{
	t_num	n;

	if (!a || is_sorted(a))
		return ;
	n.first = (*a)->head->value;
	n.second = (*a)->head->next->value;
	n.third = (*a)->head->next->next->value;
	sort_three_cases(a, bench, n);
}

int	small_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	if (is_sorted(a))
		return (0);
	if ((*a)->size == 2)
		sort_two(a, bench);
	else if ((*a)->size == 3)
		sort_three(a, bench);
	else if ((*a)->size == 4)
		sort_four(a, b, bench);
	else if ((*a)->size == 5)
		sort_five(a, b, bench);
	return (0);
}

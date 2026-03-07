/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:45:11 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:45:17 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_node	*i;
	t_node	*j;

	mistakes = 0;
	total_pairs = 0;
	if (!a || a->size < 2)
		return (0.0);
	i = a->head;
	while (i && i->next)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}

static void	set_bench(t_bench *bench, const char *class)
{
	if (!bench)
		return ;
	bench->used = STRAT_ADAPTIVE;
	bench->class_name = class;
}

static void	run_by_disorder(t_stack **a, t_stack **b,
				t_bench *bench, double disorder)
{
	if (disorder < 0.2)
	{
		set_bench(bench, "O(n^2)");
		selection_sort(a, b, bench);
	}
	else if (disorder < 0.5)
	{
		set_bench(bench, "O(n*sqrt(n))");
		chunk_sort(a, b, 10, bench);
	}
	else
	{
		set_bench(bench, "O(n*log(n))");
		lsd_algo(a, b, bench);
	}
}

void	ft_adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;

	if ((*a)->size <= 5)
	{
		set_bench(bench, "O(1)");
		small_sort(a, b, bench);
		return ;
	}
	disorder = compute_disorder(*a);
	make_indexing(*a);
	run_by_disorder(a, b, bench, disorder);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:49:55 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:49:57 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	streq(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == 0 && b[i] == 0);
}

static void	init_bench(t_bench *bench)
{
	bench->enabled = 0;
	bench->forced = STRAT_ADAPTIVE;
	bench->used = STRAT_ADAPTIVE;
	bench->class_name = NULL;
	bench->disorder = 0.0;
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

int	parse_flags(t_bench *bench, int argc, char **argv, int *start)
{
	int	i;

	i = 1;
	init_bench(bench);
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (streq(argv[i], "--bench"))
			bench->enabled = 1;
		else if (streq(argv[i], "--simple"))
			bench->forced = STRAT_SIMPLE;
		else if (streq(argv[i], "--medium"))
			bench->forced = STRAT_MEDIUM;
		else if (streq(argv[i], "--complex"))
			bench->forced = STRAT_COMPLEX;
		else if (streq(argv[i], "--adaptive"))
			bench->forced = STRAT_ADAPTIVE;
		else
			return (0);
		i++;
	}
	*start = i;
	return (1);
}

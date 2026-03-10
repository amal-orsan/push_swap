/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:39:22 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:39:28 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	run_forced(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench->forced == STRAT_SIMPLE)
	{
		bench->used = STRAT_SIMPLE;
		bench->class_name = "O(n^2)";
		selection_sort(a, b, bench);
	}
	else if (bench->forced == STRAT_MEDIUM)
	{
		bench->used = STRAT_MEDIUM;
		bench->class_name = "O(n*sqrt(n))";
		make_indexing(*a);
		chunk_sort(a, b, bench);
	}
	else if (bench->forced == STRAT_COMPLEX)
	{
		bench->used = STRAT_COMPLEX;
		bench->class_name = "O(n*log(n))";
		make_indexing(*a);
		lsd_algo(a, b, bench);
	}
	else
		ft_adaptive(a, b, bench);
}

static int	init_stack(t_stack **a, t_stack **b)
{
	*a = new_stack();
	*b = new_stack();
	if (!*a || !*b)
		return (0);
	return (1);
}

static int	load_input(t_stack **a, t_stack **b,
				char **argv, char ***split_out)
{
	char	**split;

	split = ft_split(argv[0], ' ');
	if (!split || !split[0])
		return (free_split(split), 0);
	*split_out = split;
	init_stack_a(a, b, split, split);
	return (1);
}

static void	sort_and_clean(t_stack **a, t_stack **b,
				t_bench *bench, char **split)
{
	if (bench->enabled)
		bench->disorder = compute_disorder(*a);
	if (!is_sorted(a))
		run_forced(a, b, bench);
	else
		bench->class_name = "O(1)";
	bench_print(bench);
	free_stack(a);
	free_stack(b);
	free_split(split);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	char	**split;
	int		start;

	split = NULL;
	if (argc < 2 || !parse_flags(&bench, argc, argv, &start))
	{
		if (argc < 2)
			return (0);
		else
			return (write(2, "Error\n", 6), 1);
	}
	if (start >= argc)
		return (0);
	if (!init_stack(&a, &b))
		return (1);
	if (argc - start == 1 && !load_input(&a, &b, argv + start, &split))
		return (free(a), free(b), 0);
	if (argc - start > 1)
		init_stack_a(&a, &b, argv + start, NULL);
	sort_and_clean(&a, &b, &bench, split);
	return (0);
}

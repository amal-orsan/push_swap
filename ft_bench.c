/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:44:36 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:44:42 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	count_push(t_bench *bench, char op)
{
	if (op == 'a')
		bench->pa++;
	else if (op == 'b')
		bench->pb++;
	else if (op == 'c')
		bench->rra++;
	else if (op == 'd')
		bench->rrb++;
	else
		bench->rrr++;
}

static void	count_swap_rot(t_bench *bench, char op)
{
	if (op == 'f')
		bench->sa++;
	else if (op == 'g')
		bench->sb++;
	else if (op == 'h')
		bench->ss++;
	else if (op == 'i')
		bench->ra++;
	else if (op == 'j')
		bench->rb++;
	else
		bench->rr++;
}

void	bench_count(t_bench *bench, char op)
{
	if (!bench || !bench->enabled)
		return ;
	bench->total++;
	if (op >= 'a' && op <= 'e')
		count_push(bench, op);
	else
		count_swap_rot(bench, op);
}

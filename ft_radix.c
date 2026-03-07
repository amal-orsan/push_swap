/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:42:35 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:42:38 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	max_bit(t_stack *a)
{
	int		max_bits;
	int		max;
	t_node	*cur;

	cur = a->head;
	max = cur->index;
	while (cur)
	{
		if (cur->index > max)
			max = cur->index;
		cur = cur->next;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	lsd_algo(t_stack **a, t_stack **b, t_bench *bench)
{
	int	i;
	int	bit;
	int	max_bits;
	int	size;

	size = (*a)->size;
	max_bits = max_bit(*a);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*a)->head->index >> bit) & 1) == 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			i++;
		}
		while ((*b)->size > 0)
			pa(a, b, bench);
		bit++;
	}
}

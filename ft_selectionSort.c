/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selectionSort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:41:19 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:41:22 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*find_min(t_stack *stack)
{
	t_node	*cur;
	t_node	*min_node;
	long	min;

	if (!stack || !stack->head)
		return (NULL);
	min = LONG_MAX;
	min_node = NULL;
	cur = stack->head;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_node = cur;
		}
		cur = cur->next;
	}
	return (min_node);
}

int	get_position(t_stack *stack, t_node *node)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = stack->head;
	while (cur && cur != node)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

void	selection_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	t_node	*min;
	int		pos;
	int		len;

	while ((*a)->size > 0)
	{
		min = find_min(*a);
		len = stack_len(*a);
		pos = get_position(*a, min);
		if (pos <= len / 2)
			while ((*a)->head != min)
				ra(a, bench);
		else
			while ((*a)->head != min)
				rra(a, bench);
		pb(a, b, bench);
	}
	while ((*b)->size > 0)
		pa(a, b, bench);
}

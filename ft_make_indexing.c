/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_indexing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:43:13 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:43:16 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	sort_values(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_indices(t_stack *a, int *sorted)
{
	t_node	*cur;
	int		i;

	cur = a->head;
	while (cur)
	{
		i = 0;
		while (i < a->size)
		{
			if (sorted[i] == cur->value)
			{
				cur->index = i;
				break ;
			}
			i++;
		}
		cur = cur->next;
	}
}

void	make_indexing(t_stack *a)
{
	int		*sorted;
	int		i;
	t_node	*cur;

	sorted = malloc(sizeof(int) * a->size);
	if (!sorted)
		return ;
	cur = a->head;
	i = 0;
	while (cur)
	{
		sorted[i++] = cur->value;
		cur = cur->next;
	}
	sort_values(sorted, a->size);
	assign_indices(a, sorted);
	free(sorted);
}

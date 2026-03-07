/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:43:01 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:43:03 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack *a, int n)
{
	t_node	*cur;

	if (!a)
		return (0);
	cur = a->head;
	while (cur)
	{
		if (cur->value == n)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	free_errors(t_stack **a, t_stack **b, char **split)
{
	free_stack(a);
	free_stack(b);
	free_split(split);
	write(2, "Error\n", 6);
	exit(1);
}

void	init_stack_a(t_stack **a, t_stack **b, char **argv, char **split)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a, b, split);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, b, split);
		if (error_duplicate(*a, (int)n))
			free_errors(a, b, split);
		create_and_append(*a, (int)n);
		i++;
	}
}

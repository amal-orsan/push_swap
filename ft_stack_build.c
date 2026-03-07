/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:40:20 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:40:23 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	create_and_append(t_stack *stack, int n)
{
	t_node	*node;
	t_node	*last;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = n;
	node->index = 0;
	node->next = NULL;
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
		node->prev = NULL;
	}
	else
	{
		last = stack->tail;
		last->next = node;
		node->prev = last;
		stack->tail = node;
	}
	stack->size++;
}

t_node	*find_last(t_stack *stack)
{
	if (!stack || !stack->head)
		return (NULL);
	return (stack->tail);
}

int	stack_len(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}

void	free_stack(t_stack **stack)
{
	t_node	*cur;
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	cur = (*stack)->head;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(*stack);
	*stack = NULL;
}

t_stack	*new_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
	return (s);
}

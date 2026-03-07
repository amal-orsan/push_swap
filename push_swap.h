/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:39:38 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:39:43 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_bench
{
	int			enabled;
	t_strategy	forced;
	t_strategy	used;
	const char	*class_name;
	double		disorder;
	long		total;
	long		sa;
	long		sb;
	long		ss;
	long		pa;
	long		pb;
	long		ra;
	long		rb;
	long		rr;
	long		rra;
	long		rrb;
	long		rrr;
}	t_bench;

typedef struct t_chunk
{
	t_stack	**a;
	t_stack	**b;
	int		min_idx;
	int		max_idx;
	t_bench	*bench;
}	t_chunk;

typedef struct s_num
{
	int	first;
	int	second;
	int	third;

}	t_num;

/* ops */
void		sa(t_stack **a, t_bench *bench);
void		sb(t_stack **b, t_bench *bench);
void		ss(t_stack **a, t_stack **b, t_bench *bench);
void		ra(t_stack **a, t_bench *bench);
void		rb(t_stack **b, t_bench *bench);
void		rr(t_stack **a, t_stack **b, t_bench *bench);
void		rra(t_stack **a, t_bench *bench);
void		rrb(t_stack **b, t_bench *bench);
void		rrr(t_stack **a, t_stack **b, t_bench *bench);
void		pa(t_stack **a, t_stack **b, t_bench *bench);
void		pb(t_stack **b, t_stack **a, t_bench *bench);

/* algorithms */
double		compute_disorder(t_stack *a);
void		ft_adaptive(t_stack **a, t_stack **b, t_bench *bench);
void		selection_sort(t_stack **a, t_stack **b, t_bench *bench);
void		chunk_sort(t_stack **a, t_stack **b, int chunk_count,
				t_bench *bench);
void		lsd_algo(t_stack **a, t_stack **b, t_bench *bench);

/* small sorts */
int			is_sorted(t_stack **a);
void		sort_two(t_stack **a, t_bench *bench);
void		sort_three(t_stack **a, t_bench *bench);
void		sort_four(t_stack **a, t_stack **b, t_bench *bench);
void		sort_five(t_stack **a, t_stack **b, t_bench *bench);
int			small_sort(t_stack **a, t_stack **b, t_bench *bench);

/* stack utils */
void		create_and_append(t_stack *stack, int n);
t_node		*find_last(t_stack *stack);
t_node		*find_min(t_stack *stack);
int			get_position(t_stack *stack, t_node *node);
int			stack_len(t_stack *stack);
void		free_stack(t_stack **stack);
void		make_indexing(t_stack *a);
t_stack		*new_stack(void);

/* parsing */
int			error_syntax(char *str);
int			error_duplicate(t_stack *a, int n);
void		free_errors(t_stack **a, t_stack **b, char **split);
void		init_stack_a(t_stack **a, t_stack **b, char **argv,
				char **split);

/* bench */
void		bench_count(t_bench *bench, char op);
void		bench_print(t_bench *bench);

/* flags */
int			parse_flags(t_bench *bench, int argc, char **argv, int *start);

/* utils */
long		ft_atol(char *str);
char		**ft_split(char const *s, char c);
void		free_split(char **split);

#endif

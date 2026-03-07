/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:44:48 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:44:57 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	putnbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putnbr_fd(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

static void	putstr_fd(const char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

static void	print_disorder(double ratio)
{
	long	p;

	p = (long)(ratio * 10000.0 + 0.5);
	putnbr_fd(p / 100, 2);
	putstr_fd(".", 2);
	if ((p % 100) < 10)
		putstr_fd("0", 2);
	putnbr_fd(p % 100, 2);
	putstr_fd("%\n", 2);
}

static void	print_ops(t_bench *bench)
{
	putstr_fd("[bench] sa: ", 2);
	putnbr_fd(bench->sa, 2);
	putstr_fd(" sb: ", 2);
	putnbr_fd(bench->sb, 2);
	putstr_fd(" ss: ", 2);
	putnbr_fd(bench->ss, 2);
	putstr_fd(" pa: ", 2);
	putnbr_fd(bench->pa, 2);
	putstr_fd(" pb: ", 2);
	putnbr_fd(bench->pb, 2);
	putstr_fd("\n[bench] ra: ", 2);
	putnbr_fd(bench->ra, 2);
	putstr_fd(" rb: ", 2);
	putnbr_fd(bench->rb, 2);
	putstr_fd(" rr: ", 2);
	putnbr_fd(bench->rr, 2);
	putstr_fd(" rra: ", 2);
	putnbr_fd(bench->rra, 2);
	putstr_fd(" rrb: ", 2);
	putnbr_fd(bench->rrb, 2);
	putstr_fd(" rrr: ", 2);
	putnbr_fd(bench->rrr, 2);
	putstr_fd("\n", 2);
}

void	bench_print(t_bench *bench)
{
	if (!bench || !bench->enabled)
		return ;
	putstr_fd("[bench] disorder:   ", 2);
	print_disorder(bench->disorder);
	putstr_fd("[bench] strategy:   ", 2);
	if (bench->used == STRAT_SIMPLE)
		putstr_fd("Simple", 2);
	else if (bench->used == STRAT_MEDIUM)
		putstr_fd("Medium", 2);
	else if (bench->used == STRAT_COMPLEX)
		putstr_fd("Complex", 2);
	else
		putstr_fd("Adaptive", 2);
	putstr_fd(" / ", 2);
	if (bench->class_name)
		putstr_fd(bench->class_name, 2);
	else
		putstr_fd("unknown", 2);
	putstr_fd("\n[bench] total_ops:  ", 2);
	putnbr_fd(bench->total, 2);
	putstr_fd("\n", 2);
	print_ops(bench);
}

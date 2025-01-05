/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:42:48 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 18:44:35 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_l_min(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

static long	ft_l_abs(long num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

t_best_move	calc_score(long i, long j, long from_size, long dist_size)
{
	t_best_move	calc;

	if (i < ft_l_abs(i - from_size))
		calc.from = i;
	else
		calc.from = (i - from_size);
	if (j < ft_l_abs(j - dist_size))
		calc.dist = j;
	else
		calc.dist = (j - dist_size);
	calc.score = ft_l_min(ft_l_min(ft_l_abs(calc.from), ft_l_abs(calc.dist))
			+ ft_l_abs(calc.from - calc.dist), ft_l_abs(calc.from)
			+ ft_l_abs(calc.dist));
	return (calc);
}

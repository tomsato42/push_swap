/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_best_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:00:33 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 20:32:31 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_from(t_ring_head *from, t_best_move *min, char f_side)
{
	while (0 < min->from)
	{
		list_rotate(from, from, 0, f_side);
		min->from--;
	}
	while (min->from < 0)
	{
		list_rotate(from, from, 1, f_side);
		min->from++;
	}
}

static void	rotate_dist(t_ring_head *dist, t_best_move *min, char d_side)
{
	while (0 < min->dist)
	{
		list_rotate(dist, dist, 0, d_side);
		min->dist--;
	}
	while (min->dist < 0)
	{
		list_rotate(dist, dist, 1, d_side);
		min->dist++;
	}
}

void	apply_best_move(t_ring_head *from, t_ring_head *dist,
		t_best_move min, char f_side)
{
	char	d_side;

	d_side = 'a';
	if (f_side == 'a')
		d_side = 'b';
	while (0 < min.from && 0 < min.dist)
	{
		list_rotate(from, dist, 0, 'r');
		min.dist--;
		min.from--;
	}
	while (min.from < 0 && min.dist < 0)
	{
		list_rotate(from, dist, 1, 'r');
		min.dist++;
		min.from++;
	}
	rotate_from(from, &min, f_side);
	rotate_dist(dist, &min, d_side);
	if (f_side == 'a')
		list_push(from, dist, d_side);
	else
		list_push(dist, from, d_side);
}

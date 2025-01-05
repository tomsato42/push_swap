/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_head_to_min_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:03:26 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 19:13:55 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_min(t_ring_head *a, long min_point)
{
	long	i;

	i = 0;
	if (min_point < (long)a->size - min_point)
	{
		while (i < min_point)
		{
			list_rotate(a, a, 0, 'a');
			i++;
		}
	}
	else
	{
		while (i < (long)a->size - min_point)
		{
			list_rotate(a, a, 1, 'a');
			i++;
		}
	}
}

void	move_head_to_min_value(t_ring_head *a)
{
	long	i;
	long	min;
	long	min_point;

	i = 0;
	min = a->head->value;
	while (i < (long)a->size)
	{
		if (a->head->value < min)
		{
			min = a->head->value;
			min_point = i;
		}
		a->head = a->head->next;
		i++;
	}
	rotate_to_min(a, min_point);
}

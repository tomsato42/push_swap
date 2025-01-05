/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:40:38 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 20:26:49 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	greedy_sort(t_ring_head *a, t_ring_head *b)
{
	size_t	i;

	i = 0;
	while (i++ < 3)
		list_push(a, b, 'b');
	sort_small_list(b, 'b');
	while (3 < a->size)
		apply_best_move(a, b, find_best_move(a, b, 1), 'a');
	sort_small_list(a, 'a');
	while (b->size != 0)
		apply_best_move(b, a, find_best_move(b, a, 0), 'b');
	move_head_to_min_value(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_small_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:19:52 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 20:39:16 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_size_two(t_ring_head *list_a, t_ring_head *list_b)
{
	list_swap(list_a, list_b, 'a');
}

static void	handle_size_three(t_ring_head *list_a, t_ring_head *list_b)
{
	sort_small_list(list_a, 'a');
	move_head_to_min_value(list_a);
	(void)list_b;
}

static void	handle_size_four(t_ring_head *list_a, t_ring_head *list_b)
{
	size_t	i;

	i = 0;
	while (i++ < 3)
		list_push(list_a, list_b, 'b');
	sort_small_list(list_b, 'b');
	list_push(list_a, list_b, 'a');
	while (list_b->size != 0)
		apply_best_move(list_b, list_a, find_best_move(list_b, list_a, 0), 'b');
	move_head_to_min_value(list_a);
}

static void	handle_size_five(t_ring_head *list_a, t_ring_head *list_b)
{
	list_push(list_a, list_b, 'b');
	list_push(list_a, list_b, 'b');
	sort_small_list(list_a, 'a');
	while (list_b->size != 0)
		apply_best_move(list_b, list_a, find_best_move(list_b, list_a, 0), 'b');
	move_head_to_min_value(list_a);
}

void	handle_small_list(t_ring_head *list_a, t_ring_head *list_b)
{
	if (list_a->size == 2)
		handle_size_two(list_a, list_b);
	else if (list_a->size == 3)
		handle_size_three(list_a, list_b);
	else if (list_a->size == 4)
		handle_size_four(list_a, list_b);
	else if (list_a->size == 5)
		handle_size_five(list_a, list_b);
}

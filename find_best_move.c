/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:46:07 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 19:53:18 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_better_move(t_ring_head *from, t_ring_head *dist,
		t_best_move best, t_best_move score)
{
	const int	node_value = from->head->value;

	if (dist->head == NULL || dist->head->prev == NULL
		|| dist->head->next == NULL)
		return (0);
	if (score.score < best.score)
	{
		if (dist->head->prev->value < node_value)
		{
			if (node_value < dist->head->value)
				return (1);
			if (dist->head->value < dist->head->prev->value)
				return (1);
		}
		if (node_value < dist->head->value
			&& dist->head->value < dist->head->prev->value)
			return (1);
	}
	return (0);
}

static int	is_better_move_rev(t_ring_head *from, t_ring_head *dist,
		t_best_move best, t_best_move score)
{
	const int	node_value = from->head->value;

	if (dist->head == NULL || dist->head->prev == NULL
		|| dist->head->next == NULL)
		return (0);
	if (score.score < best.score)
	{
		if (node_value < dist->head->prev->value)
		{
			if (dist->head->value < node_value)
				return (1);
			if (dist->head->prev->value < dist->head->value)
				return (1);
		}
		if (dist->head->value < node_value
			&& dist->head->prev->value < dist->head->value)
			return (1);
	}
	return (0);
}

t_best_move	find_best_move(t_ring_head *from, t_ring_head *dist,
		int is_rev)
{
	t_best_move	best;
	t_best_move	score;
	long		i;
	long		j;

	i = 0;
	j = 0;
	best.score = LONG_MAX;
	while (i < (long)from->size)
	{
		while (j < (long)dist->size)
		{
			score = calc_score(i, j, (long)from->size, (long)dist->size);
			if (is_better_move(from, dist, best, score) && (is_rev == 0))
				best = score;
			if (is_better_move_rev(from, dist, best, score) && (is_rev == 1))
				best = score;
			dist->head = dist->head->next;
			j++;
		}
		from->head = from->head->next;
		j = 0;
		i++;
	}
	return (best);
}

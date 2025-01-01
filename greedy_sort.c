/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:40:38 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/01 19:11:11 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_min_move
{
	long			a;
	long			b;
	long			score;
}					t_min_move;

static t_min_move	find_min_move(t_ring_head *from, t_ring_head *dist)
{
	t_min_move	min;

	min.a = 1;
	min.b = 1;
	min.score = 1;
	return (min);
}

static void	move(t_ring_head *from, t_min_move *dist, t_min_move min)
{
}

static void	sort_3_number(t_ring_head *list)
{
}

static void	head_to_min_node(t_ring_head *a)
{
}

void	greedy_sort(t_ring_head *a, t_ring_head *b)
{
	size_t		i;
	t_min_move	min;

	i = 0;
	while (i++ < 2)
		list_push(a, b, 'b');
	while (a->size < 3)
	{
		min = find_min_move(a, b);
		move(a, b, min);
	}
	sort_3_number(a);
	while (b->size != 0)
	{
		min = find_min_move(b, a);
		move(b, a, min);
	}
	head_to_min_node(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:00:14 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 10:22:10 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_ring_head *from, t_ring_head *dist)
{
	t_ring	*node;

	if (from->head == NULL)
		return ;
	node = from->head;
	from->head->next->prev = from->head->prev;
	from->head->prev->next = from->head->next;
	from->head = from->head->next;
	if (dist->head == NULL)
	{
		dist->head = node;
		dist->head->next = node;
		dist->head->prev = node;
	}
	else
	{
		node->next = dist->head;
		node->prev = dist->head->prev;
		dist->head->prev->next = node;
		dist->head->prev = node;
		dist->head = node;
	}
	from->size--, dist->size++;
	if (from->size == 0)
		from->head = NULL;
}

void	list_push(t_ring_head *a, t_ring_head *b, char mode)
{
	if (mode != 'a' && mode != 'b')
		return ;
	if (mode == 'a')
	{
		push(b, a);
		write(1, "pa\n", 3);
	}
	else if (mode == 'b')
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
}
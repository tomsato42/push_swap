/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:00:14 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/12 13:11:33 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static void	push(t_ring_head *from, t_ring_head *dist, t_ring *node)
{
	if (from->head == NULL)
		return ;
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
	from->size--;
	dist->size++;
	if (from->size == 0)
		from->head = NULL;
}

int	list_push_check(t_ring_head *a, t_ring_head *b, char mode)
{
	if (mode != 'a' && mode != 'b')
		return (1);
	if (mode == 'a')
	{
		if (b->head == NULL)
			return (1);
		push(b, a, b->head);
	}
	else if (mode == 'b')
	{
		if (a->head == NULL)
			return (1);
		push(a, b, a->head);
	}
	return (0);
}

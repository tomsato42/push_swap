/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:26:36 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/11 15:07:39 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	list_rotate_check(t_ring_head *a, t_ring_head *b, int is_rev, char mode)
{
	if (mode != 'a' && mode != 'b' && mode != 'r')
		return ;
	if (mode == 'a' || mode == 'r')
	{
		if (is_rev && a->head != NULL)
			a->head = a->head->prev;
		else if (a->head != NULL)
			a->head = a->head->next;
	}
	if (mode == 'b' || mode == 'r')
	{
		if (is_rev && b->head != NULL)
			b->head = b->head->prev;
		else if (b->head != NULL)
			b->head = b->head->next;
	}
}

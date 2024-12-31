/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:26:36 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/31 16:52:52 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_rotate(t_ring_head *a, t_ring_head *b, int is_rev, char mode)
{
	if (mode != 'a' && mode != 'b' && mode != 'r')
		return ;
	if (mode == 'a' || mode == 'r')
		if (is_rev)
			a->head = a->head->prev;
		else
			a->head = a->head->next;
	if (mode == 'b' || mode == 'r')
		if (is_rev)
			b->head = b->head->prev;
		else
			b->head = b->head->next;
	write(1, "r", 1);
	if (is_rev)
		write(1, "r", 1);
	write(1, &mode, 1);
	write(1, "\n", 1);
}

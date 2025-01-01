/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:59:11 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/01 17:31:36 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_free(t_ring_head *list)
{
	t_ring	*node;
	t_ring	*next;

	if (!list)
		return ;
	if (!list->head)
	{
		free(list);
		return ;
	}
	node = list->head;
	while (1)
	{
		next = node->next;
		free(node);
		node = next;
		if (node == list->head)
			break ;
	}
	free(list);
}
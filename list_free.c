/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:59:11 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/31 14:27:21 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_free(t_ring_head *list)
{
	t_ring	*node;
	t_ring	*next;

	if (!list || !list->head)
		return ;
	
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
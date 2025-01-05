/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:52:38 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 20:18:28 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_list(t_ring_head *list, char side)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	if (list->size == 2)
		if (list->head->next->value < list->head->value)
			list_swap(list, list, side);
	if (list->size == 3)
	{
		while (i < 3)
		{
			if (list->head->value < list->head->next->value)
				flag++;
			list->head = list->head->next;
			i++;
		}
		if (flag != 2 && side == 'a')
			list_swap(list, list, side);
		else if (flag != 1 && side == 'b')
			list_swap(list, list, side);
	}
}

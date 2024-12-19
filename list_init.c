/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:13:37 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/19 20:21:04 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ring_head	*list_init(void)
{
	t_ring_head	*new_list;

	new_list = (t_ring_head *)malloc(sizeof(t_ring_head));
	if (!new_list)
	{
		PRINT_ERROR();
		return (NULL);
	}
	new_list->head = NULL;
	new_list->size = 0;
	return (new_list);
}

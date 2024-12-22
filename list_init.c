/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:13:37 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/21 18:55:06 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ring_head	*list_init(void)
{
	t_ring_head	*new_list;

	new_list = (t_ring_head *)malloc(sizeof(t_ring_head));
	if (!new_list)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	new_list->head = NULL;
	new_list->size = 0;
	return (new_list);
}

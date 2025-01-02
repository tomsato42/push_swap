/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:55:40 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/02 16:07:57 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ring	*list_new(t_ring_head *list, int value)
{
	t_ring *new;
	t_ring *tail;

	new = (t_ring *)malloc(sizeof(t_ring));
	if (!new)
		return (NULL);
	new->value = value;
	if (list->head == NULL)
	{
		list->head = new;
		list->head->next = new;
		list->head->prev = new;
		list->size = 1;
	}
	else
	{
		tail = list->head->prev;
		new->prev = tail;
		new->next = list->head;
		list->head->prev = new;
		tail->next = new;
		list->size += 1;
	}
	return (new);
}

void list_add_tail(t_ring_head *list, int *arr, size_t arr_size)
{
	size_t	i;

	i = 0;
	while (i < arr_size)
	{
		if(list_new(list, arr[i]) == NULL)
		{
			list_free(list);
			write(2,"Error\n",6);
		}
		i++;
	}
}



/*
             list->head
                ▼
        ┌───────┐     ┌───────┐     ┌───────┐
       │   1          │<─▶│   2          │<─▶│      3       │
      ├───┬───┤     ├───┬───┤     ├───┬───┤
     │prev  │  next│─▶ │ prev │ next │─▶ │prev  │next  │
    └───┴───┘     └───┴───┘     └───┴───┘
       ▲                                                     │
       └──────────────────────────┘
*/

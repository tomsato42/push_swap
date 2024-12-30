/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:55:40 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/30 20:37:37 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ring	*list_new(t_ring_head *list, int value)
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
		list_new(list, arr[i]);
		//ここで、malloc失敗してNULLが返ってきたときにリストの要素をすべてfreeする
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	int i = 0;
// 	int size = 5;
// 	int arr[5] = {2, 3, 4, 5, 1};
// 	t_ring_head *list = list_init();
// 	list_add_tail(list,arr,size);
// 	t_ring *ptr = list->head;
// 	while (i < (list->size)*2)
// 	{
// 		printf("%d, ",ptr->value);	
// 		ptr = ptr->next;
// 		i++;
// 	}

// 	free(list);
// 	return (0);
// }

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
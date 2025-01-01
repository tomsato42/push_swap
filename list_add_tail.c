/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:55:40 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/01 17:42:22 by tomsato          ###   ########.fr       */
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

#include <stdio.h>

void print_list(t_ring_head *list) {
	t_ring *ptr = list->head;
	for (size_t i = 0; i < list->size; i++) {
		printf("%d, ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}

int main(int argc, char **argv) {
	int *arr = is_input_enabled(argc, argv);
	if (!arr)
		return 1;
	t_ring_head *list = list_init();
	list_add_tail(list, arr, argc - 1);
	t_ring_head *list2 = list_init();
	//list_add_tail(list2,arr,argc - 1);
	free(arr);
	if (!list)
		return 1;
	if (!list2)
		return 1;
	printf("Init list\n");
	print_list(list);
	print_list(list2);
	printf("\n");
	list_swap(list,list2,'a');
	print_list(list);
	print_list(list2);
	printf("\n");
	// list_swap(list, list2, 's');
	//list_rotate(list,list2,1,'r');
	for (int i = 0; i < 3; i++) {
		list_push(list, list2, 'b');
	}
	print_list(list);
	print_list(list2);
	printf("\n");
	list_rotate(list,list2,0,'a');
	list_rotate(list,list2,0,'b');
	print_list(list);
	print_list(list2);
	printf("\n");
	list_rotate(list,list2,1,'a');
	list_rotate(list,list2,1,'b');
	print_list(list);
	print_list(list2);
	printf("\n");
	list_swap(list,list2,'a');
	print_list(list);
	print_list(list2);
	printf("\n");
	for (int i = 0; i < 3; i++) {
		list_push(list, list2, 'a');
	}
	print_list(list);
	print_list(list2);
	printf("\n");
	list_free(list);
	list_free(list2);
	return 0;
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
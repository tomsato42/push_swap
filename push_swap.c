/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:58:39 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 19:44:48 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			*arr;
	t_ring_head	*list_a;
	t_ring_head	*list_b;

	arr = is_input_enabled(argc, argv);
	if (!arr)
		return (1);
	list_a = list_init();
	list_add_tail(list_a, arr, argc - 1);
	list_b = list_init();
	free(arr);
	if (!list_a || !list_b)
		return (1);
	handle_small_list(list_a, list_b);
	greedy_sort(list_a, list_b);
	list_free(list_a);
	list_free(list_b);
	return (0);
}

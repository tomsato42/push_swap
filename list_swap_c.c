/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:23:01 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/12 13:19:20 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	list_swap_check(t_ring_head *a, t_ring_head *b, char mode)
{
	if (mode != 'a' && mode != 'b' && mode != 's')
		return (1);
	if (mode == 'a' || mode == 's')
	{
		if (a->head == NULL)
			return (1);
		else if (a->head == a->head->next)
			return (1);
		else if (a->head != NULL)
			swap(&a->head->value, &a->head->next->value);
	}
	if (mode == 'b' || mode == 's')
	{
		if (b->head == NULL)
			return (1);
		else if (b->head == b->head->next)
			return (1);
		else if (b->head != NULL)
			swap(&b->head->value, &b->head->next->value);
	}
	return (0);
}

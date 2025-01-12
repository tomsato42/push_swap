/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free_and_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:49:17 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/12 14:11:34 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_free_and_exit(t_ring_head *a, t_ring_head *b, char *buffer)
{
	list_free(a);
	list_free(b);
	free(buffer);
	write(1, "KO\n", 3);
	exit(1);
}

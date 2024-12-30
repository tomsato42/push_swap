/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_isdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:30:08 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/30 19:54:42 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_isdup(int *arr, size_t size)
{
	size_t	i;
	int		*copy_arr;

	copy_arr = (int *)malloc(size * sizeof(int));
	if (!copy_arr)
		return (1);
	i = 0;
	while (i < size)
	{
		copy_arr[i] = arr[i];
		i++;
	}
	merge_sort(0, size - 1, copy_arr);
	i = 0;
	while (i < size - 1)
	{
		if (copy_arr[i] == copy_arr[i + 1])
		{
			free(copy_arr);
			return(1);
		}
		i++;
	}
	free(copy_arr);
	return (0);
}

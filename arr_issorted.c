/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_issorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:07:12 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/30 19:19:54 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_issorted(int *arr, size_t size)
{
	int	prev_value;
	size_t	n;
	
	n = 1;
	while (n < size)
	{
		prev_value = arr[n - 1];
		if(arr[n] <= prev_value)
			return (0);
		n++;
	}
	return (1);
}

/*
#include <stdio.h>
int main()
{
	int arr1[5] = {1,2,3,4,5};
	int arr2[5] = {1,2,3,5,4};
	int arr3[5] = {0,1,1,1,1};

	printf("arr1:%d\n",arr_issorted(arr1,5));
	printf("arr2:%d\n",arr_issorted(arr2,5));
	printf("arr3:%d\n",arr_issorted(arr3,5));
	return 0;
}
*/
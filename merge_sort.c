/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:29:06 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/21 18:26:34 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(size_t start, size_t end, int *arr, int *tmp)
{
	const size_t	center = start + (end - start) / 2;
	size_t			right;
	size_t			left;
	size_t			i;

	right = start;
	left = center + 1;
	i = 0;
	while (start + i <= end)
	{
		if (arr[right] < arr[left] && right <= center)
			tmp[i++] = arr[right++];
		else if (arr[left] < arr[right] && left <= end)
			tmp[i++] = arr[left++];
		else if (right <= center)
			tmp[i++] = arr[right++];
		else if (left <= end)
			tmp[i++] = arr[left++];
	}
}

int	merge_sort(size_t start, size_t end, int *arr)
{
	const size_t	center = start + (end - start) / 2;
	size_t			i;
	int				*tmp;

	if ((end - start) > 1)
	{
		merge_sort(start, center, arr);
		merge_sort(center + 1, end, arr);
	}
	i = 0;
	tmp = (int *)malloc((end - start + 1) * sizeof(int));
	if (!tmp)
		return (1);
	merge(start, end, arr, tmp);
	i = 0;
	while (start + i <= end)
	{
		arr[start + i] = tmp[i];
		i++;
	}
	free(tmp);
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>

// void print_array(int *arr, size_t size)
// {
//     for (size_t i = 0; i < size; i++)
//         printf("%d, ", arr[i]);
//     printf("\n");
// }

// int main()
// {
//     // Test Case 1: Single element
//     int arr1[1] = {42};
//     printf("Test Case 1: Single Element\n");
//     print_array(arr1, 1);
//     merge_sort(0, 0, arr1);
//     print_array(arr1, 1);

//     // Test Case 2: All same values
//     int arr2[5] = {5, 5, 5, 5, 5};
//     printf("\nTest Case 2: All Same Values\n");
//     print_array(arr2, 5);
//     merge_sort(0, 4, arr2);
//     print_array(arr2, 5);

//     // Test Case 3: Already sorted
//     int arr3[5] = {-5, 0, 3, 7, 15};
//     printf("\nTest Case 3: Already Sorted\n");
//     print_array(arr3, 5);
//     merge_sort(0, 4, arr3);
//     print_array(arr3, 5);

//     // Test Case 4: Reverse sorted
//     int arr4[5] = {15, 7, 3, 0, -5};
//     printf("\nTest Case 4: Reverse Sorted\n");
//     print_array(arr4, 5);
//     merge_sort(0, 4, arr4);
//     print_array(arr4, 5);

//     // Test Case 5: Odd and even number of elements
//     int arr5[7] = {7, 3, 8, 2, 5, 1, 4};
//     printf("\nTest Case 5a: Odd Number of Elements\n");
//     print_array(arr5, 7);
//     merge_sort(0, 6, arr5);
//     print_array(arr5, 7);

//     int arr6[6] = {9, -2, 4, 1, 0, 5};
//     printf("\nTest Case 5b: Even Number of Elements\n");
//     print_array(arr6, 6);
//     merge_sort(0, 5, arr6);
//     print_array(arr6, 6);

//     // Test Case 6: Empty array
//     printf("\nTest Case 6: Empty Array\n");
//     int arr7[0] = {};
//     print_array(arr7, 0);
//     merge_sort(0, 0, arr7);
//     print_array(arr7, 0);

//     // Test Case 7: Large array
//     int arr8[1000];
//     for (int i = 0; i < 1000; i++)
//         arr8[i] = rand() % 2000 - 1000;
//     printf("\nTest Case 7: Large Array\n");
//     merge_sort(0, 999, arr8);
//     // Uncomment next line to see the sorted large array
//     // print_array(arr8, 1000);

//     return 0;
// }

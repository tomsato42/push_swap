/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_enabled.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:58:17 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 18:39:44 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*is_input_enabled(int argc, char **argv)
{
	int	*input;

	if (argc < 2)
		return (NULL);
	input = parse_input(argc, argv);
	if (input == NULL)
		return (NULL);
	else if (arr_isdup(input, argc - 1))
	{
		write(2, "Error\n", 6);
		free(input);
		input = NULL;
	}
	else if (arr_issorted(input, argc - 1))
	{
		free(input);
		input = NULL;
	}
	return (input);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	int *input;

// 	input = is_input_enabled(argc, argv);
// 	if(input)
// 	{
// 		for(int i = 0; i < argc - 1; i++)
// 		{
// 			printf("%d\n",input[i]);
// 		}
// 		free(input);
// 	}
// 	return (0);
// }
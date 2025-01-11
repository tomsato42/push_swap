/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:09:39 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/11 17:04:06 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#define OVER_INT_MAX "2147483647"
#define OVER_INT_MIN "2147483648"

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	check_boundary(char *s, int is_minus)
{
	int	n;

	n = -1;
	if (is_minus == 1)
	{
		while (++n < 10)
		{
			if (OVER_INT_MIN[n] < s[n])
				return (1);
			if (OVER_INT_MIN[n] > s[n])
				return (0);
		}
	}
	else
	{
		while (++n < 10)
		{
			if (OVER_INT_MAX[n] < s[n])
				return (1);
			if (OVER_INT_MAX[n] > s[n])
				return (0);
		}
	}
	return (0);
}

static int	check_overflow(char *s)
{
	int		is_minus;
	size_t	s_len;

	is_minus = 0;
	if (*s == '-')
		is_minus = 1;
	if (*s == '+' || *s == '-')
		s++;
	s_len = ft_strlen(s);
	if (s_len < 10)
		return (0);
	else if (s_len == 10)
		return (check_boundary(s, is_minus));
	else
		return (1);
}

int	validate_input(char *s)
{
	if (!*s)
	{
		return (0);
	}
	if (check_overflow(s) == 1)
	{
		return (0);
	}
	if (*s == '+' || *s == '-')
	{
		s++;
		if (!(*s))
			return (0);
	}
	while (*s)
	{
		if (ft_isdigit(*s))
			s++;
		else
			return (0);
	}
	return (1);
}

int	*parse_input(int argc, char **argv)
{
	int	*input_values;
	int	i;

	i = 0;
	input_values = (int *)malloc((argc - 1) * sizeof(int));
	if (input_values == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	while (i < argc - 1)
	{
		if (validate_input(argv[i + 1]) == 0)
		{
			write(2, "Error\n", 6);
			free(input_values);
			return (NULL);
		}
		input_values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (input_values);
}

// int	main(int argc, char *argv[])
// {
// 	int	i;
// 	int	*input;
// 	int *input2;

// 	input = parse_input(argc, argv);
// 	input2 = parse_input(argc, argv);
// 	if (input == NULL)
// 		return (0);
// 	printf("isdup : %d\n", arr_isdup(input, argc - 1));
// 	printf("Number of arguments (argc): %d\n", argc);
// 	printf("Arguments (argv):\n");
// 	i = 0;
// 	while (i < argc)
// 	{
// 		printf("  argv[%d]: %s\n", i, argv[i]);
// 		i++;
// 	}
// 	printf("Parsed input values:\n");
// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		printf("  input[%d]: %d\n", i, input[i]);
// 		i++;
// 	}
// 	free(input);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:42:22 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/12 14:54:28 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static void	apply_move(t_ring_head *list_a, t_ring_head *list_b, int id,
		char *operations)
{
	if (id < 3)
	{
		if (list_swap_check(list_a, list_b, "abs"[id]))
		{
			list_free_and_exit(list_a, list_b, operations);
		}
	}
	else if (id < 5)
	{
		if (list_push_check(list_a, list_b, "ab"[id - 3]))
		{
			list_free_and_exit(list_a, list_b, operations);
		}
	}
	else if (list_rotate_check(list_a, list_b, id > 7, "abr"[(id - 5) % 3]))
	{
		list_free_and_exit(list_a, list_b, operations);
	}
}

static int	validate_operations(t_ring_head *list_a, t_ring_head *list_b,
		char *operations)
{
	int			i;
	const char	*ops[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
		"rrb", "rrr"};

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(operations, ops[i], ft_strlen(ops[i]) + 1))
		{
			apply_move(list_a, list_b, i, operations);
			return (0);
		}
		i++;
	}
	if (!ft_strncmp(operations, "sa", ft_strlen("sa") + 1))
		apply_move(list_a, list_b, 0, operations);
	else if (!ft_strncmp(operations, "sb", ft_strlen("sb") + 1))
		apply_move(list_a, list_b, 1, operations);
	else
		return (1);
	return (0);
}

static int	list_issorted(t_ring_head *list_a, t_ring_head *list_b)
{
	size_t	i;
	int		max;

	if (list_b->head != NULL)
		return (0);
	i = 1;
	max = list_a->head->value;
	list_a->head = list_a->head->next;
	while (i < list_a->size)
	{
		if (list_a->head->value < max)
			return (0);
		list_a->head = list_a->head->next;
		i++;
	}
	return (1);
}

int	checker(t_ring_head *list_a, t_ring_head *list_b)
{
	char	*buffer;

	while (1)
	{
		buffer = read_stdin();
		if (buffer == NULL)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (*buffer == 'E')
			break ;
		if (validate_operations(list_a, list_b, buffer))
		{
			write(2, "Error\n", 6);
			free(buffer);
			return (1);
		}
		free(buffer);
	}
	if (list_issorted(list_a, list_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int argc, char **argv)
{
	int			*arr;
	t_ring_head	*list_a;
	t_ring_head	*list_b;

	arr = is_input_enabled_check(argc, argv);
	if (!arr)
		return (1);
	list_a = list_init();
	list_add_tail(list_a, arr, argc - 1);
	list_b = list_init();
	free(arr);
	if (!list_a || !list_b)
		return (1);
	checker(list_a, list_b);
	list_free(list_a);
	list_free(list_b);
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// // read_stdinテスト用のmain関数
// int main()
// {
//     char *result;

//     printf("Enter input (up to 4 characters per line, or EOF to end):\n");
//     while (1)
//     {
//         result = read_stdin();
//         if (result == NULL)
//         {
//             printf("Memory allocation failed.\n");
//             return (1);
//         }
//         else if (*result == 'E')
//         {
//             printf("EOF encountered.\n");
//             break ;
//         }
//         else
//         {
//             printf("Read: %s\n", result);
//             free(result);
//         }
//     }
//     return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:40:38 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/04 17:37:14 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#define LONG_MAX 9223372036854775807
typedef struct s_best_move
{
	long			from;
	long			dist;
	long			score;
}					t_best_move;

static long	ft_l_min(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

static long	ft_l_abs(long num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

static t_best_move	calc_score(long i, long j, long from_size, long dist_size)
{
	t_best_move	calc;

	if (i < ft_l_abs(i - from_size))
		calc.from = i;
	else
		calc.from = (i - from_size);
	if (j < ft_l_abs(j - dist_size))
		calc.dist = j;
	else
		calc.dist = (j - dist_size);
	;
	calc.score = ft_l_min(ft_l_min(ft_l_abs(calc.from), ft_l_abs(calc.dist))
			+ ft_l_abs(calc.from - calc.dist), ft_l_abs(calc.from)
			+ ft_l_abs(calc.dist));
	return (calc);
}

static int	is_better_move(t_ring_head *from, t_ring_head *dist,
		t_best_move best, t_best_move score)
{
	const int	node_value = from->head->value;

	if (score.score < best.score)
	{
		if (dist->head->prev->value < node_value)
		{
			if (node_value < dist->head->next->value)
				return (1);
			if (dist->head->value < dist->head->prev->value)
				return (1);
		}
		if (node_value < dist->head->value)
			if (dist->head->prev->value < dist->head->value)
				return (1);
	}
	return (0);
}

static t_best_move	find_best_move(t_ring_head *from, t_ring_head *dist)
{
	t_best_move	best;
	t_best_move	score;
	long		i;
	long		j;

	i = 0;
	j = 0;
	best.score = LONG_MAX;
	while (i < (long)from->size)
	{
		while (j < (long)dist->size)
		{
			score = calc_score(i, j, (long)from->size, (long)dist->size);
			if (is_better_move(from, dist, best, score))
				best = score;
			dist->head = dist->head->next;
			j++;
		}
		from->head = from->head->next;
		j = 0;
		i++;
	}
	return (best);
}

// static void	apply_best_move(t_ring_head *from, t_best_move *dist,
//		t_best_move min)
// {
// }

// static void	sort_small_list(t_ring_head *list)
// {
// }

// static void	move_head_to_min_value(t_ring_head *a)
// {
// }

// void	greedy_sort(t_ring_head *a, t_ring_head *b)
// {
// 	size_t		i;
// 	t_best_move	min;

// 	i = 0;
// 	while (i++ < 2)
// 		list_push(a, b, 'b');
// 	while (a->size < 3)
// 	{
// 		min = find_best_move(a, b);
// 		apply_best_move(a, b, min);
// 	}
// 	sort_small_list(a);
// 	while (b->size != 0)
// 	{
// 		min = find_best_move(b, a);
// 		apply_best_move(b, a, min);
// 	}
// 	move_head_to_min_value(a);
// }

#include <stdio.h>

void	print_list(t_ring_head *list)
{
	t_ring	*ptr;

	ptr = list->head;
	for (size_t i = 0; i < list->size; i++)
	{
		printf("%d, ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int			*arr;
	t_best_move	best;
	t_ring_head	*list;
	t_ring_head	*list2;

	arr = is_input_enabled(argc, argv);
	if (!arr)
		return (1);
	list = list_init();
	list_add_tail(list, arr, argc - 1);
	list2 = list_init();
	// list_add_tail(list2, arr, argc - 1);
	free(arr);
	if (!list || !list2)
		return (1);
	printf("Init list\n");
	print_list(list);
	print_list(list2);
	printf("\n");
	// list_swap(list, list2, 'a');
	// print_list(list);
	// print_list(list2);
	// printf("\n");
	// list_swap(list, list2, 's');
	// list_rotate(list,list2,1,'r');
	for (int i = 0; i < 3; i++)
	{
		list_push(list, list2, 'b');
	}
	print_list(list);
	print_list(list2);
	printf("\n");
	// printf("%zu,%zu\n",list->size,list2->size);
	best = find_best_move(list, list2);
	printf("\nresult : \ni = %ld\nj = %ld\nscore = %ld\n\n", best.from,
		best.dist, best.score);
	print_list(list);
	print_list(list2);
	printf("\n");
	// list_rotate(list, list2, 0, 'a');
	// list_rotate(list, list2, 0, 'b');
	// print_list(list);
	// print_list(list2);
	// printf("\n");
	// list_rotate(list, list2, 1, 'a');
	// list_rotate(list, list2, 1, 'b');
	// print_list(list);
	// print_list(list2);
	// printf("\n");
	// list_swap(list, list2, 'a');
	// print_list(list);
	// print_list(list2);
	// printf("\n");
	// for (int i = 0; i < 3; i++) {
	// 	list_push(list, list2, 'a');
	// }
	// print_list(list);
	// print_list(list2);
	// printf("\n");
	list_free(list);
	list_free(list2);
	return (0);
}

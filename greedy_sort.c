/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:40:38 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/04 20:21:15 by tomsato          ###   ########.fr       */
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

	if (dist->head == NULL || dist->head->prev == NULL
		|| dist->head->next == NULL)
		return (0);
	if (score.score < best.score)
	{
		if (dist->head->prev->value < node_value)
		{
			if (node_value < dist->head->value)
				return (1);
			if (dist->head->value < dist->head->prev->value)
				return (1);
		}
		if (node_value < dist->head->value
			&& dist->head->value < dist->head->prev->value)
			return (1);
	}
	return (0);
}

// static int is_better_move(t_ring_head *from, t_ring_head *dist, t_best_move best, t_best_move score)
// {
//     const int node_value = from->head->value;

//     if (dist->head == NULL || dist->head->prev == NULL || dist->head->next == NULL)
//         return 0;

//     printf("Checking if move is better:\n");
//     printf("Current node value: %d\n", node_value);
//     printf("dist->head->prev->value: %d\n", dist->head->prev->value);
//     printf("dist->head->value: %d\n", dist->head->value);
//     printf("dist->head->next->value: %d\n", dist->head->next->value);
//     printf("Current score: %ld, Best score: %ld\n", score.score, best.score);

//     if (score.score < best.score)
//     {
//         if (dist->head->prev->value < node_value)
//         {
//             if (node_value < dist->head->value)
//             {
//                 printf("Debug: Condition 1 met: dist->head->prev->value < node_value < dist->head->value\n");
//             }
//             if (dist->head->value < dist->head->prev->value)
//             {
//                 printf("Debug: Condition 2 met: dist->head->value < dist->head->prev->value\n");
//             }
//             if (node_value < dist->head->value)
//                 return 1;
//             if (dist->head->value < dist->head->prev->value)
//                 return 1;
//         }
//         if (node_value < dist->head->value && dist->head->value < dist->head->prev->value)
//         {
//             printf("Debug: Condition 3 met: node_value < dist->head->value < dist->head->prev->value\n");
//             return 1;
//         }
//     }
//     return 0;
// }

#include <stdio.h>

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

static void	apply_best_move(t_ring_head *from, t_ring_head *dist,
		t_best_move min, char f_side)
{
	char	d_side;

	d_side = 'a';
	if (f_side == 'a')
		d_side = 'b';
	while (0 < min.from && 0 < min.dist)
		list_rotate(from, dist, 0, 'r'), min.dist--, min.from--;
	while (min.from < 0 && min.dist < 0)
		list_rotate(from, dist, 1, 'r'), min.dist++, min.from++;
	while (0 < min.from)
		list_rotate(from, dist, 0, f_side), min.from--;
	while (0 < min.dist)
		list_rotate(from, dist, 0, d_side), min.dist--;
	while (min.from < 0)
		list_rotate(from, dist, 1, f_side), min.from++;
	while (min.dist < 0)
		list_rotate(from, dist, 1, d_side), min.dist++;
	list_push(from, dist, d_side);
}

static void	sort_small_list(t_ring_head *list, char side)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	if (list->size == 2)
		if (list->head->next->value < list->head->value)
			list_swap(list, list, side);
	if (list->size == 3)
	{
		while (i < 3)
		{
			if (list->head->value < list->head->next->value)
				flag++;
			list->head = list->head->next;
			i++;
		}
		if (flag != 2)
			list_swap(list, list, side);
	}
}

static void	move_head_to_min_value(t_ring_head *a)
{
	long	i;
	long	min;
	long	min_point;

	i = 0;
	min = a->head->value;
	while(i < (long)a->size)
	{
		if (a->head->value < min)
		{
			min = a->head->value;
			min_point = i;
		}
		a->head = a->head->next;
		i++;
	}
	i = 0;
	if (min_point < (long)a->size - min_point)
		while (i < min_point)
			list_rotate(a, a, 0, 'a'),i++;
	else
		while (i < (long)a->size - min_point)
			list_rotate(a, a, 1, 'a'),i++;
}

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
	t_ring_head	*list;
	t_ring_head	*list2;

	arr = is_input_enabled(argc, argv);
	if (!arr)
		return (1);
	list = list_init();
	list_add_tail(list, arr, argc - 1);
	list2 = list_init();
	free(arr);
	if (!list || !list2)
		return (1);
	for (int i = 0; i < 3; i++)
		list_push(list, list2, 'b');
	sort_small_list(list2,'b');
	while (3 < list->size)
		apply_best_move(list,list2,find_best_move(list,list2),'a');
	sort_small_list(list, 'a');
	while (list2->size != 0)
		apply_best_move(list, list2, find_best_move(list2,list),'b');
	move_head_to_min_value(list),list_free(list),list_free(list2);
	return (0);
}

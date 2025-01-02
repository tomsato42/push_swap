/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:40:38 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/02 22:58:46 by tomsato          ###   ########.fr       */
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
		return a;
	else
		return b;
}

static long	ft_l_abs(long num)
{
	if (num < 0)
		return -num;
	else
		return num;
}

static t_best_move	calc_score(long i, long j, long from_size, long dist_size)
{
	t_best_move	calc;

	printf("if (i(%ld) < ft_l_abs(i(%ld) - from_size(%ld))(%ld))\n",i,i,from_size,ft_l_abs(i - from_size));
	if (i < ft_l_abs(i - from_size))
		calc.from = i;
	else
		calc.from = (i - from_size);
	printf("if (j(%ld) < ft_l_abs(j(%ld) - dist_size(%ld))(%ld))\n",j,j,dist_size,ft_l_abs(j - dist_size));
	if (j < ft_l_abs(j - dist_size))
		calc.dist = j;
	else
		calc.dist = (j - dist_size);;
	printf("calc.score = min(min(abs(%ld), abs(%ld)) + abs(%ld, - %ld), abs(%ld) + abs(%ld)));",calc.from,calc.dist,calc.from,calc.dist,calc.from,calc.dist);
	calc.score = ft_l_min(ft_l_min(ft_l_abs(calc.from), ft_l_abs(calc.dist)) + ft_l_abs(calc.from - calc.dist), ft_l_abs(calc.from) + ft_l_abs(calc.dist));
	return (calc);
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
		printf("\n\ni = %ld\n",i);
		while (j < (long)dist->size)
		{
			printf("\n\nj=%ld\n",j);
			score = calc_score(i,j,(long)from->size,(long)dist->size);
			printf("score:i=%ld,j=%ld,score=%ld\n",score.from,score.dist,score.score);
			printf("from->head->value(%d) < dist->head->value(%d)\n",from->head->value,dist->head->value);
			if (score.score < best.score
				&& ((from->head->value < dist->head->value)
					&& (dist->head->value < from->head->value)))
			//ここの条件式をもっとちゃんと整理する
			{
				write(1,"yeah\n",5);
				best = score;
			}
			dist->head = dist->head->next;
			j++;
		}
		from->head = from->head->next;
		j = 0;
		i++;
	}
	return (best);
}

// static void	apply_best_move(t_ring_head *from, t_best_move *dist, t_best_move min)
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

void print_list(t_ring_head *list) {
	t_ring *ptr = list->head;
	for (size_t i = 0; i < list->size; i++) {
		printf("%d, ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}

int main(int argc, char **argv) {
	int *arr = is_input_enabled(argc, argv);
	if (!arr)
		return 1;
	t_best_move	best;

	t_ring_head *list = list_init();
	list_add_tail(list, arr, argc - 1);

	t_ring_head *list2 = list_init();
	//list_add_tail(list2, arr, argc - 1);
	free(arr);
	if (!list || !list2)
		return 1;

	printf("Init list\n");
	print_list(list);
	print_list(list2);
	printf("\n");
	// list_swap(list, list2, 'a');
	// print_list(list);
	// print_list(list2);
	// printf("\n");
	// list_swap(list, list2, 's');
	//list_rotate(list,list2,1,'r');
	for (int i = 0; i < 3; i++) {
		list_push(list, list2, 'b');
	}
	print_list(list);
	print_list(list2);
	printf("\n");
	// printf("%zu,%zu\n",list->size,list2->size);
	best = find_best_move(list,list2);
	printf("\nresult : \ni = %ld\nj = %ld\nscore = %ld\n\n",best.from,best.dist,best.score);
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
	// list_free(list);
	// list_free(list2);
	return 0;
}

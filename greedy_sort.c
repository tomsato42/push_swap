/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:40:38 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/02 01:33:49 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (i < ft_l_abs(i - from_size))
		calc.from = i;
	else
		calc.from = (i - from_size);
	if (j < ft_l_abs(j - dist_size))
		calc.dist = j;
	else
		calc.dist = (j - dist_size);;
	calc.score = ft_l_min(ft_l_min(ft_l_abs(calc.from), ft_l_abs(calc.dist)) + ft_l_abs(calc.from - calc.dist), ft_l_abs(calc.from) + ft_l_abs(calc.dist));
	return (calc);
}

static t_best_move	find_best_move(t_ring_head *from, t_ring_head *dist)
{
	t_best_move	best;
	long		i;
	long		j;

	i = 0;
	j = 0;
	while (i < from->size)
	{
		while (j < dist->size)
		{

			dist->head = dist->head->next;
			j++;
		}
		from->head = from->head->next;
		i++;
	}

	return (best);
}

static void	apply_best_move(t_ring_head *from, t_best_move *dist, t_best_move min)
{
}

static void	sort_small_list(t_ring_head *list)
{
}

static void	move_head_to_min_value(t_ring_head *a)
{
}

void	greedy_sort(t_ring_head *a, t_ring_head *b)
{
	size_t		i;
	t_best_move	min;

	i = 0;
	while (i++ < 2)
		list_push(a, b, 'b');
	while (a->size < 3)
	{
		min = find_best_move(a, b);
		apply_best_move(a, b, min);
	}
	sort_small_list(a);
	while (b->size != 0)
	{
		min = find_best_move(b, a);
		apply_best_move(b, a, min);
	}
	move_head_to_min_value(a);
}

// #include <assert.h>
// #include <stdio.h>

// void test_calc_score(void)
// {
// 	// テストケース1: 両方上方向回転
// 	t_best_move result1 = calc_score(1, 3, 5, 5);
// 	printf("Test 1 (上方向回転): from=%ld, dist=%ld, score=%ld\n",
// 		   result1.from, result1.dist, result1.score);

// 	// テストケース2: fromが上、distが下方向
// 	t_best_move result2 = calc_score(1, 4, 5, 5);
// 	printf("Test 2 (上下混合): from=%ld, dist=%ld, score=%ld\n",
// 		   result2.from, result2.dist, result2.score);

// 	// テストケース3: fromが下、distが上方向
// 	t_best_move result3 = calc_score(4, 1, 5, 5);
// 	printf("Test 3 (下上混合): from=%ld, dist=%ld, score=%ld\n",
// 		   result3.from, result3.dist, result3.score);

// 	// テストケース4: 両方下方向回転
// 	t_best_move result4 = calc_score(4, 4, 5, 5);
// 	printf("Test 4 (下方向回転): from=%ld, dist=%ld, score=%ld\n",
// 		   result4.from, result4.dist, result4.score);

// 	printf("\nAll calc_score tests completed!\n");
// }

// int main(void)
// {
//     test_calc_score();
//     return 0;
// }

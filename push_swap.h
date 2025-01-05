/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:58:36 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/05 20:53:45 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define LONG_MAX 9223372036854775807

/*双方向循環リスト(Doubly Circular List)*/
typedef struct s_ring
{
	struct s_ring	*next;
	struct s_ring	*prev;
	int				value;
}					t_ring;

/*双方向循環リストの先頭*/

typedef struct s_ring_head
{
	t_ring			*head;
	size_t			size;
}					t_ring_head;

/*移動を評価するための構造体*/
typedef struct s_best_move
{
	long			from;
	long			dist;
	long			score;
}					t_best_move;

/*リストのメモリアドレスを確保*/
t_ring_head			*list_init(void);
/*入力の文字列をint型に変換*/
int					*parse_input(int argc, char **argv);
/*リストの末尾に要素を追加する*/
void				list_add_tail(t_ring_head *list, int *arr, size_t arr_size);
/*文字列を数字に変換*/
int					ft_atoi(const char *nptr);
/*文字列の長さを返す*/
size_t				ft_strlen(const char *s);
/*int型の配列をソートする*/
int					merge_sort(size_t start, size_t end, int *arr);
/*配列がソートされているかを調べる*/
int					arr_issorted(int *arr, size_t size);
/*入力が有効かを調べ、有効ならint型の配列にして返す*/
int					*is_input_enabled(int argc, char **argv);
/*int型の配列に重複した要素がないかを調べる*/
int					arr_isdup(int *arr, size_t size);
/*リストをfreeする*/
void				list_free(t_ring_head *list);
/*sa,sb,ssを実行、modeにa,b,sを指定する*/
void				list_swap(t_ring_head *a, t_ring_head *b, char mode);
/*ra,b,r,rra,b,rを実行する*/
void				list_rotate(t_ring_head *a, t_ring_head *b, int is_rev,
						char mode);
/*pa,pbを実行する。*/
void				list_push(t_ring_head *a, t_ring_head *b, char mode);
/*リストをソートする*/
void				greedy_sort(t_ring_head *a, t_ring_head *b);
/*移動を評価する*/
t_best_move			calc_score(long i, long j, long from_size, long dist_size);
/*一番適切な移動を見つける*/
t_best_move			find_best_move(t_ring_head *from, t_ring_head *dist,
						int is_rev);
/*見つけた組み合わせをもとに配列を移動させる関数*/
void				apply_best_move(t_ring_head *from, t_ring_head *dist,
						t_best_move min, char f_side);
/*3以下の大きさのリストをソートする*/
void				sort_small_list(t_ring_head *list, char side);
/*一番小さい数を適切に一番上に持ってくる*/
void				move_head_to_min_value(t_ring_head *a);
/*小さいリストを特別に処理する*/
void				handle_small_list(t_ring_head *list_a, t_ring_head *list_b);

#endif

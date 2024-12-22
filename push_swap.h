/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:58:36 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/21 18:55:19 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*双方向循環リスト(Doubly Circular List)*/
typedef struct s_ring
{
	int				value;
	struct s_ring	*next;
	struct s_ring	*prev;

}					t_ring;

/*双方向循環リストの先頭*/
typedef struct s_ring_head
{
	t_ring			*head;
	size_t			size;
}					t_ring_head;

/*リストのメモリアドレスを確保*/
t_ring_head			*list_init(void);
/*入力の文字列をint型に変換*/
int					*parse_input(int argc, char **argv);
/*リストの末尾に要素を追加する*/
void				list_add_tail(t_ring_head *ring_head, int value);
/*文字列を数字に変換*/
int					ft_atoi(const char *nptr);
/*文字列の長さを返す*/
size_t				ft_strlen(const char *s);
/*int型の配列をソートする*/
int					merge_sort(size_t start, size_t end, int *arr);
/*int型の配列に重複した要素がないかを調べる*/
int					arr_isdup(int *arr, size_t size);

#endif

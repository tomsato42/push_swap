/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:58:36 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/19 21:06:06 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>

/* エラー出力マクロ */
# define PRINT_ERROR() (write(2, "Error\n", 6))

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
int					*parse_input(int argc, char *argv, int *input_values);
/*リストの末尾に要素を追加する。*/
void				list_add_tail(t_ring_head *ring_head, int value);
/*文字列を数字に変換*/
int	ft_atoi(const char *nptr);

#endif
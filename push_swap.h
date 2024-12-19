/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:58:36 by tomsato           #+#    #+#             */
/*   Updated: 2024/12/19 18:39:19 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>

/*双方向循環リスト(Doubly Circular List)*/
typedef struct s_ring
{
	int				value;
	struct s_ring	*next;
	struct s_ring	*prev;
	
}	t_ring;

typedef struct s_ring_head
{
	t_ring	*head;
	size_t	size;
}	t_ring_head;


#endif
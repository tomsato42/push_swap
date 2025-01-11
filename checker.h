/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:43:00 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/11 18:29:03 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
//文字を出力しない版の操作関数とか書いておく
# define EOF (-1)
# include "push_swap.h"
# include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	list_swap_check(t_ring_head *a, t_ring_head *b, char mode);
void	list_push_check(t_ring_head *a, t_ring_head *b, char mode);
void	list_rotate_check(t_ring_head *a, t_ring_head *b, int is_rev,
			char mode);
int		*is_input_enabled_check(int argc, char **argv);
char	*read_stdin(void);

#endif
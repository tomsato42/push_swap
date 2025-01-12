/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:43:00 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/12 14:44:41 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
//文字を出力しない版の操作関数とか書いておく
# define EOF (-1)
# include "push_swap.h"
# include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		list_swap_check(t_ring_head *a, t_ring_head *b, char mode);
int		list_push_check(t_ring_head *a, t_ring_head *b, char mode);
int		list_rotate_check(t_ring_head *a, t_ring_head *b, int is_rev,
			char mode);
int		*is_input_enabled_check(int argc, char **argv);
char	*read_stdin(void);
void	list_free_and_exit(t_ring_head *a, t_ring_head *b, char *buffer);

#endif
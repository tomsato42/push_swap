/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:28:29 by tomsato           #+#    #+#             */
/*   Updated: 2025/01/11 18:29:48 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	read_stdin_char(int fd)
{
	static char	buffer[100];
	static char	*buffer_pointer;
	static int	n;

	if (n == 0)
	{
		n = read(fd, buffer, sizeof buffer);
		buffer_pointer = buffer;
	}
	if (0 <= --n)
		return ((unsigned char)*buffer_pointer++);
	else
		return (EOF);
}

char	*read_stdin(void)
{
	char	*buffer;
	int		return_val;
	size_t	i;

	buffer = (char *)malloc(5 * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		return_val = read_stdin_char(0);
		if (return_val == EOF)
		{
			free(buffer);
			return ("E");
		}
		buffer[i] = return_val;
		if (return_val == '\n')
			break ;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:56:38 by hng          #+#    #+#             */
/*   Updated: 2019/10/31 20:56:38 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	get_next_line(int fd, char **line)
{
	char	b[1];
	int		i;

	if (line == 0 || fd < 0)
		return (-1);
	*line = 0;
	b[0] = 'x';
	while (b[0] != '\n')
	{
		i = read(fd, b, 1);
		if (i && b[0] != '\n')
			*line = join_char_and_free(*line, b[0]);
		else
			break ;
	}
	return (i && b[0] == '\n');
}

/* ************************************************************************** */
/*[\t]                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:35:53 by hng          #+#    #+#             */
/*   Updated: 2019/10/09 15:35:53 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		buffer[10000];
	char		*destcpy;
	char		*source;

	source = (char *)src;
	destcpy = dest;
	i = 0;
	while (i < n)
	{
		buffer[i] = source[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		destcpy[i] = buffer[i];
		i++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:19:41 by hng          #+#    #+#             */
/*   Updated: 2019/10/09 19:19:41 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	result = (char *)s;
	i = 0;
	while (result[i])
	{
		if (result[i] == c)
			return (result + i);
		i++;
	}
	if (result[i] == 0 && c == 0)
		return (result + i);
	return (NULL);
}

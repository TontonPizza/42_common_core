/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:33:20 by hng          #+#    #+#             */
/*   Updated: 2019/10/10 10:33:20 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		result[i] = (char)s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

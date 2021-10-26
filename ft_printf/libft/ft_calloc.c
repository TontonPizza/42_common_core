/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:25:36 by hng          #+#    #+#             */
/*   Updated: 2019/10/10 10:25:36 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t count, size_t size)
{
	void		*result;

	if (!(result = malloc(size * count)))
	{
		return (NULL);
	}
	ft_bzero(result, count * size);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 07:21:51 by vo-nguye          #+#    #+#             */
/*   Updated: 2020/01/01 07:21:51 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	special_malloc(void *item, int size, int count)
{
	item = malloc(size * count);
	if (item == 0)
		return (0);
	return (1);
}

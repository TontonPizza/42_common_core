/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:58:33 by hng          #+#    #+#             */
/*   Updated: 2019/11/26 10:58:33 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_zero(const char *format, va_list a)
{
	char		*result;
	t_params	params;
	int			i;

	params = read_params(format + 1, '\0', a);
	update_params(&params, 0);
	result = ft_strdup_to_c(format + params.invalid + 1, '\0');
	i = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:14:55 by hng          #+#    #+#             */
/*   Updated: 2019/11/26 11:14:55 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*format_data_pc(char *d, t_params p)
{
	char	*r;
	int		i;

	r = ft_strdup(d);
	free(d);
	if (ft_strlen(d) != 0)
	{
		while (p.hpoint && p.point > ft_strlen(r))
			r = char_join_and_free(r, '0');
	}
	while (p.hzero && p.zero > ft_strlen(r))
		r = char_join_and_free(r, p.hpoint ? ' ' : '0');
	while (p.hhyphen && p.hyphen > ft_strlen(r))
		r = join_char_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width > 0 && p.width > ft_strlen(r))
		r = char_join_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width < 0 && -p.width > ft_strlen(r))
		r = join_char_and_free(r, ' ');
	return (r);
}

int			parse_pc(const char *format, va_list a)
{
	int			i;
	int			k;
	char		*result;
	t_params	params;

	k = 0;
	params = read_params(format + 1, '%', a);
	update_params(&params, '%');
	result = ft_strdup("%");
	if (params.invalid != -1)
	{
		free(result);
		result = ft_strdup_to_c(format + params.invalid + 1, '%');
		result[ft_strlen(result) - 1] = 0;
	}
	else
		result = format_data_pc(result, params);
	i = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}

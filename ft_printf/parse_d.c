/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:39:00 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/26 00:39:00 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*format_data_d(char *d, t_params p, int neg)
{
	char	*r;
	int		i;

	r = ft_strdup(d);
	free(d);
	if (ft_strlen(d) != 0)
	{
		while (p.hpoint && p.point > ft_strlen(r))
			r = char_join_and_free(r, '0');
		r = p.hpoint && neg < 0 ? char_join_and_free(r, '-') : r;
	}
	r = !p.hpoint && neg < 0 &&
		(!p.hzero || p.zero <= ft_strlen(r)) ? char_join_and_free(r, '-') : r;
	while (p.hzero && p.zero > ft_strlen(r))
		r = char_join_and_free(r, p.hpoint ? ' ' : '0');
	r[0] = r[0] == '0' && neg < 0 ? '-' : r[0];
	while (p.hhyphen && p.hyphen > ft_strlen(r))
		r = join_char_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width > 0 && p.width > ft_strlen(r))
		r = char_join_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width < 0 && -p.width > ft_strlen(r))
		r = join_char_and_free(r, ' ');
	return (r);
}

int			parse_d(const char *format, va_list a)
{
	int			data;
	char		*result;
	t_params	p;
	int			i;

	i = 0;
	p = read_params(format + 1, 'd', a);
	update_params(&p, 'd');
	data = va_arg(a, int);
	if (data == 0 && p.point == 0 && p.hpoint)
		result = ft_strdup("");
	else
		result = vo_itoa(data);
	if (p.invalid != -1)
	{
		free(result);
		result = ft_strdup_to_c(format + p.invalid + 1, 'd');
	}
	result = format_data_d(result, p, data);
	i = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}

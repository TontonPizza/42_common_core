/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:58:37 by hng          #+#    #+#             */
/*   Updated: 2019/11/06 15:58:37 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_char_and_free(char *str, char c)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)x_malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str && str[i] != 0)
	{
		result[i] = str[i];
		i++;
	}
	result[i++] = c;
	result[i] = 0;
	free(str);
	return (result);
}

char	*char_join_and_free(char *str, char c)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (result == NULL)
	{
		free(str);
		return (NULL);
	}
	result[0] = c;
	while (str && str[i] != 0)
	{
		result[i + 1] = str[i];
		i++;
	}
	result[i + 1] = 0;
	free(str);
	return (result);
}

char	*strjoin_free_2(char *t1, char *t2)
{
	char	*result;

	result = ft_strjoin_and_free(t1, t2);
	free(t2);
	return (result);
}

char	*ft_strjoin_and_free(char *t1, char *t2)
{
	char		*result;
	int			i;
	int			k;

	result = malloc(sizeof(char) * (ft_strlen(t1) + ft_strlen(t2) + 1));
	if (result == NULL)
	{
		free(t1);
		return (NULL);
	}
	i = 0;
	k = 0;
	while (t1 && t1[i])
	{
		result[i] = t1[i];
		i++;
	}
	while (t2 && t2[k])
	{
		result[i + k] = t2[k];
		k++;
	}
	result[i + k] = 0;
	free(t1);
	return (result);
}

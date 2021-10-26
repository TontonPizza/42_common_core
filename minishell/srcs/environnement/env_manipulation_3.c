/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manipulation_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/69 11:29:15 by hng          #+#    #+#             */
/*   Updated: 2021/03/69 11:29:15 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void 	import_all_env(char **env)
{
	int		i;
	int		k;
	char	*name;
	char	*value;

	i = 0;
	while (env[i])
	{
		k = 0;
		while (env[i][k] && env[i][k] != '=')
			k++;
		name = ft_strdup(env[i]);
		name[k] = 0;
		if (env[i][k])
			k++;
		value = ft_strdup(env[i] + k);
		export_var(name, value);
		free(name);
		free(value);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullshit_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/65 19:46:00 by hng          #+#    #+#             */
/*   Updated: 2021/03/65 19:46:00 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char 	*join_2_char_bullshit(char *src, char *word, int *i)
{
	char	*result;

	result = join_char_and_free(src, word[(*i)]);
	result = join_char_and_free(result, word[(*i) + 1]);
	*i += 2;
	return (result);
}

int	ptr_p(int *ptr, int i)
{
	*ptr += i;
	return (1);
}

void 	free_if_not_null(void *ptr)
{
	return ;
	if (ptr != 0)
	{
		free(ptr);
		ptr = 0;
	}
}

int	define_redirect(int red, char c)
{
	if (c == ARROW_RIGHT)
		return (1);
	if (c == PIPE_C)
		return (0);
	return (red);
}

char	**fix_words(char **words)
{
	char	**result;
	int		i;
	int		redirect;

	result = x_malloc(sizeof(char *));
	result[0] = 0;
	redirect = 0;
	i = 0;
	while (words[i])
	{
		redirect = define_redirect(redirect, words[i][0]);
		if (words[i][0] == '\x14' && redirect == 1)
		{
			result = split_join_string(result, "\x13");
			result = split_join_string(result, "ignore");
			redirect = 0;
		}
		result = split_join_string(result, words[i++]);
	}
	if (free_split(words) && redirect == 1)
	{
		result = split_join_string(result, "\x13");
		result = split_join_string(result, "ignore");
	}
	return (result);
}

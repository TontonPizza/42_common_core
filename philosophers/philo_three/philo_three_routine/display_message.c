/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:02:18 by hng          #+#    #+#             */
/*   Updated: 2021/03/29 13:02:18 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void		display_message_three(unsigned long timestamp, int id, char *msg)
{
	if (sem_wait(g_sem_lock) != 0)
		return ;
	printf("%ld %d %s\n", timestamp, id + 1, msg);
	if (sem_post(g_sem_lock) != 0)
		return ;
}

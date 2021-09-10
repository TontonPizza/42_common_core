#include "../../headers/push_swap.h"

char	*reverse_move(char *move)
{
	if (vo_strcmp(move, PA) == 0)
		return (ft_strdup(PB));
	if (vo_strcmp(move, PB) == 0)
		return (ft_strdup(PA));
	if (vo_strcmp(move, SS) == 0)
		return (ft_strdup(SS));
	if (vo_strcmp(move, SA) == 0)
		return (ft_strdup(SA));
	if (vo_strcmp(move, SB) == 0)
		return (ft_strdup(SB));
	if (vo_strcmp(move, RA) == 0)
		return (ft_strdup(RRA));
	if (vo_strcmp(move, RRA) == 0)
		return (ft_strdup(RA));
	if (vo_strcmp(move, RB) == 0)
		return (ft_strdup(RRB));
	if (vo_strcmp(move, RRB) == 0)
		return (ft_strdup(RB));
	if (vo_strcmp(move, RR) == 0)
		return (ft_strdup(RR));
	if (vo_strcmp(move, RRR) == 0)
		return (ft_strdup(RRR));
	else
		return (0);
}

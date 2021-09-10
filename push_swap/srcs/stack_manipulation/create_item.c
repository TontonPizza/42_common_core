#include "../../headers/push_swap.h"

t_item	*create_item(int value)
{
	t_item	*item;

	item = x_malloc(sizeof(t_item));
	item->value = value;
	item->next = 0;
	return (item);
}

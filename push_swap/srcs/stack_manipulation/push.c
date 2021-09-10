#include "../../headers/push_swap.h"

void 	push(t_item **stack, int value)
{
	t_item	*item;

	item = create_item(value);
	item->next = *stack;
	*stack = item;
}

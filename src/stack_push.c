#include "../include/Header.h"

void	stack_push(stack **a, stack **b, char format)
{
	stack	*tmp;

	if (format == 'a')
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
		ft_printf("pa\n");
	}
	else if (format == 'b')
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
		ft_printf("pb\n");
	}
}

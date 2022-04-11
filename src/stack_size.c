#include "../include/Header.h"

int	stack_size(stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i += 1;
		lst = lst->next;
	}
	return (i);
}

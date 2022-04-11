#include "../include/Header.h"

void	stack_swap_both(stack **lst1, stack **lst2)
{
	stack_swap(lst1, ' ');
	stack_swap(lst2, ' ');
	ft_printf("ss\n");
}

void	stack_swap(stack **lst, char format)
{
	stack	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = (*lst)->next;
		(*lst)->next = tmp;
		if (format == 'b')
			ft_printf("sb\n");
		if (format == 'a')
			ft_printf("sa\n");
	}
}

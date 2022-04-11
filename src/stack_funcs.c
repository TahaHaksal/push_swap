#include "../include/Header.h"

stack	*stack_last(stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	stack_append(stack **lst, stack *new)
{
	stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = stack_last(*lst);
	tmp->next = new;
}

void	stack_prepend(stack **lst, stack *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

int	stack_a_is_sorted(stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

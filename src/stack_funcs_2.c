#include "../include/Header.h"

stack	*find_largest(stack **lst)
{
	stack	*tmp;
	stack	*needle;

	if (!(*lst))
		return (NULL);
	tmp = *lst;
	needle = tmp->next;
	while (needle)
	{
		if (tmp->value < needle->value)
			tmp = needle;
		needle = needle->next;
	}
	return (tmp);
}

stack	*smallest_big_equal(stack *lst, int needle)
{
	stack	*tmp;

	tmp = find_largest(&lst);
	while (lst)
	{
		if (lst->value > needle && lst->value < tmp->value)
		{
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

int	stack_index(stack *lst, stack *needle)
{
	int	i;

	if (!lst || !needle)
		return (-1);
	i = 0;
	while (lst != needle)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	find_smaller_than_mid(stack	*lst, stack *mid)
{
	while (lst)
	{
		if (lst->value < mid->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

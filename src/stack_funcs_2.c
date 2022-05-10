/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:27:54 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 13:39:44 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

t_stack	*find_largest(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*needle;

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

t_stack	*smallest_big_equal(t_stack *lst, int needle)
{
	t_stack	*tmp;

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

int	stack_index(t_stack *lst, t_stack *needle)
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

int	find_smaller_than_mid(t_stack	*lst, t_stack *mid)
{
	while (lst)
	{
		if (lst->value < mid->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

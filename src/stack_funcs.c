/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:27:58 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 13:39:45 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	stack_append(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = stack_last(*lst);
	tmp->next = new;
}

void	stack_prepend(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

int	stack_a_is_sorted(t_stack *lst)
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

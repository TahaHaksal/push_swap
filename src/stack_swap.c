/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:28:17 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 13:39:47 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

void	stack_swap_both(t_stack **lst1, t_stack **lst2)
{
	stack_swap(lst1, ' ');
	stack_swap(lst2, ' ');
	ft_printf("ss\n");
}

void	stack_swap(t_stack **lst, char format)
{
	t_stack	*tmp;

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

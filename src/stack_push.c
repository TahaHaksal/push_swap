/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:28:03 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 13:39:50 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

void	stack_push(t_stack **a, t_stack **b, char format)
{
	t_stack	*tmp;

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

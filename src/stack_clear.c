/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:39:28 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 15:30:09 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

void	stack_clear(t_stack **lst)
{
	t_stack	*tmp;

	if (lst)
	{
		if (!*lst)
			return ;
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
}

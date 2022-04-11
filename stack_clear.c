/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:39:28 by mhaksal           #+#    #+#             */
/*   Updated: 2022/04/11 13:39:29 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Header.h"

void	stack_clear(stack **lst)
{
	stack	*tmp;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_counts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:41:26 by mhaksal           #+#    #+#             */
/*   Updated: 2022/04/11 13:41:27 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

int	stack_count(stack *lst, stack *needle, char format)
{
	int	i;

	i = 0;
	if ((format != 'b' && format != 'a') || !needle || !lst)
	{
		ft_printf("Wrong Format. Try using 'b' for before or 'a' for after\n");
		return (-1);
	}
	if (format == 'b')
	{
		while (lst->value != needle->value)
		{
			lst = lst->next;
			i++;
		}
		return (i);
	}
	else
	{
		while (needle->value != stack_last(lst)->value)
		{
			needle = needle->next;
			i++;
		}
		return (i);
	}
}

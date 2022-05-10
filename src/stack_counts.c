/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_counts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:41:26 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 13:39:46 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

int	stack_count_after(t_stack *lst, t_stack *needle)
{
	int	i;

	i = 0;
	while (needle->value != stack_last(lst)->value)
	{
		needle = needle->next;
		i++;
	}
	return (i);
}

int	stack_count_before(t_stack *lst, t_stack *needle)
{
	int	i;

	i = 0;
	while (lst->value != needle->value)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	stack_count(t_stack *lst, t_stack *needle, char format)
{
	if ((format != 'b' && format != 'a') || !needle || !lst)
	{
		ft_printf("Wrong Format. Try using 'b' for before or 'a' for after\n");
		return (-1);
	}
	if (format == 'b')
		return (stack_count_before(lst, needle));
	else
		return (stack_count_after(lst, needle));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:28:06 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 13:39:49 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

void	stack_reverse_rotate_both(t_stack **lst1, t_stack **lst2)
{
	stack_reverse_rotate(lst1, ' ');
	stack_reverse_rotate(lst2, ' ');
	ft_printf("rrr\n");
}

void	stack_reverse_rotate(t_stack **lst, char format)
{
	t_stack	*tmp;

	tmp = *lst;
	if (!*lst || !(*lst)->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	if (format == 'a')
		ft_printf("rra\n");
	else if (format == 'b')
		ft_printf("rrb\n");
}

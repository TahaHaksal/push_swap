/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:28:08 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 13:39:51 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

void	stack_rotate_both(t_stack **lst1, t_stack **lst2)
{
	stack_rotate(lst1, ' ');
	stack_rotate(lst2, ' ');
	ft_printf("rr\n");
}

void	stack_rotate(t_stack **lst, char format)
{
	t_stack	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = stack_last(*lst);
	tmp->next = *lst;
	tmp = (*lst)->next;
	(*lst)->next = NULL;
	*lst = tmp;
	if (format == 'a')
		ft_printf("ra\n");
	else if (format == 'b')
		ft_printf("rb\n");
}

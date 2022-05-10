/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:28:13 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 15:21:04 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

t_stack	*stack_smallest(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst->next;
	while (tmp)
	{
		if (tmp->value < lst->value)
			lst = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

void	sort_stack_3(t_stack **lst1)
{
	t_stack	*large;

	large = find_largest(lst1);
	if (stack_count(*lst1, large, 'b') == 0)
	{
		stack_rotate(lst1, 'a');
		if ((*lst1)->value > (*lst1)->next->value)
			stack_swap(lst1, 'a');
	}
	else if (stack_count(*lst1, large, 'b') == 1)
	{
		stack_reverse_rotate(lst1, 'a');
		if ((*lst1)->value > (*lst1)->next->value)
			stack_swap(lst1, 'a');
	}
	else if ((*lst1)->value > (*lst1)->next->value)
		stack_swap(lst1, 'a');
}

void	sort_stack_small_num(t_stack **lst1, t_stack **lst2)
{
	t_stack	*small;

	while (!stack_a_is_sorted(*lst1))
	{
		small = stack_smallest(*lst1);
		if (stack_count(*lst1, small, 'b') <= stack_count(*lst1, small, 'a'))
		{
			while ((*lst1)->value != small->value)
				stack_rotate(lst1, 'a');
			if (!stack_a_is_sorted(*lst1))
				stack_push(lst1, lst2, 'b');
		}
		else
		{
			while ((*lst1)->value != small->value)
				stack_reverse_rotate(lst1, 'a');
			if (!stack_a_is_sorted(*lst1))
				stack_push(lst1, lst2, 'b');
		}
	}
	while (*lst2)
		stack_push(lst1, lst2, 'a');
}

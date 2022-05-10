/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:51 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 15:34:07 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

t_stack	*last_occur(t_stack *lst, t_stack *mid)
{
	t_stack	*tmp;

	tmp = NULL;
	while (lst)
	{
		if (lst->value < mid->value)
			tmp = lst;
		lst = lst->next;
	}
	if (!tmp)
		return (NULL);
	return (tmp);
}

t_stack	*first_occur(t_stack *lst, t_stack *mid)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->value < mid->value)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_stack	*find_av(t_stack *lst)
{
	int		i;
	t_stack	*tmp1;
	int		small;
	int		smallest;

	smallest = -2147483648;
	small = 0;
	i = 0;
	while (i < 40 && stack_size(lst) - i > 0)
	{
		tmp1 = lst;
		small = 2147483647;
		while (tmp1)
		{
			if (tmp1->value < small && tmp1->value > smallest)
				small = tmp1->value;
			tmp1 = tmp1->next;
		}
		smallest = small;
		i++;
	}
	while (lst->value != smallest)
		lst = lst->next;
	return (lst);
}

void	stack_sort_b(t_stack **lst1, t_stack **lst2)
{
	t_stack	*largest;

	while (*lst2)
	{
		largest = find_largest(lst2);
		if (stack_count(*lst2, largest, 'b') < stack_count(*lst2, largest, 'a'))
		{
			while ((*lst2)->value != largest->value)
				stack_rotate(lst2, 'b');
			stack_push(lst1, lst2, 'a');
		}
		else
		{
			while ((*lst2)->value != largest->value)
				stack_reverse_rotate(lst2, 'b');
			stack_push(lst1, lst2, 'a');
		}
	}
}

void	stack_sort(t_stack **lst1, t_stack **lst2)
{
	t_stack	*mid;
	t_stack	*first;
	t_stack	*last;

	while (!stack_a_is_sorted(*lst1))
	{
		mid = find_av(*lst1);
		while (!find_smaller_than_mid(*lst1, mid))
		{
			last = last_occur(*lst1, mid);
			first = first_occur(*lst1, mid);
			if (stack_count(*lst1, first, 'b')
				< stack_count(*lst1, last, 'a') && first)
				stack_rotate_and_push(lst1, lst2, first);
			else if (last)
			{
				while ((*lst1)->value != last->value)
					stack_reverse_rotate(lst1, 'a');
				stack_push(lst1, lst2, 'b');
			}
		}
	}
	stack_sort_b(lst1, lst2);
}

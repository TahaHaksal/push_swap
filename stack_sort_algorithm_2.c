/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:02:51 by mhaksal           #+#    #+#             */
/*   Updated: 2022/04/11 13:42:30 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Header.h"

stack	*last_occur(stack *lst, stack *mid)
{
	stack	*tmp;

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

stack	*first_occur(stack *lst, stack *mid)
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

stack	*find_av(stack *lst)
{
	int		i;
	int		count;
	stack	*tmp;

	i = 0;
	count = 0;
	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp)
	{
		count += tmp->value;
		tmp = tmp->next;
		i++;
	}
	count /= i;
	return (smallest_big_equal(lst, count));
}

void	stack_sort_b(stack **lst1, stack **lst2)
{
	stack	*largest;

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

void	stack_sort(stack **lst1, stack **lst2)
{
	stack	*mid;
	stack	*first;
	stack	*last;

	while (!stack_a_is_sorted(*lst1))
	{
		mid = find_av(*lst1);
		while (!find_smaller_than_mid(*lst1, mid))
		{
			last = last_occur(*lst1, mid);
			first = first_occur(*lst1, mid);
			if (stack_count(*lst1, first, 'b') < stack_count(*lst1, last, 'a') && first)
			{
				while ((*lst1)->value != first->value)
					stack_rotate(lst1, 'a');
				stack_push(lst1, lst2, 'b');
			}
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

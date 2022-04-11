/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:35:11 by mhaksal           #+#    #+#             */
/*   Updated: 2022/04/11 13:38:47 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Header.h"

void	print_stack(stack *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->value);
		lst = lst->next;
	}
	ft_printf("----\nlist");
}

int	stack_check(char **ptr)
{
	int	i;
	int	j;

	j = 0;
	while (ptr[j])
	{
		i = 0;
		while (ptr[j][i])
		{
			if ((ptr[j][i] != ' ' && ptr[j][i] < '0') ||
			(ptr[j][i] > '9' && ptr[j][i] != '-'))
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int	stack_check_2(stack *a)
{
	stack	*i;
	stack	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (j->value == i->value)
				return (-1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

stack	*stack_arr(char **ptr)
{
	stack	*lst;
	int		i;

	i = 0;
	lst = NULL;
	while (ptr[i])
	{
		stack_append(&lst, stack_new(ft_atoi(ptr[i])));
		i++;
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	int		check;
	stack	*a;
	stack	*b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	check = stack_check(&argv[1]);
	a = stack_arr(&argv[1]);
	if (stack_check_2(a) == -1 || check == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	b = NULL;
	stack_sort(&a, &b);
	// print_stack(a);
	return (0);
}

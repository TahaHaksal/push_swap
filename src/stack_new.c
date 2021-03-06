/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:28:01 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 13:39:51 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

t_stack	*stack_new(int value)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	tmp->value = value;
	tmp->next = NULL;
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_norm_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:41:02 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 15:32:06 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.h"

void	stack_rotate_and_push(t_stack **lst1, t_stack **lst2, t_stack *needle)
{
	while ((*lst1)->value != needle->value)
		stack_rotate(lst1, 'a');
	stack_push(lst1, lst2, 'b');
}

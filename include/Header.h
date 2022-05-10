/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:36:25 by mhaksal           #+#    #+#             */
/*   Updated: 2022/05/09 15:21:09 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft.h"
# include <stdio.h>
# include "ft_printf.h"

typedef struct f_stack
{
	int				value;
	struct f_stack	*next;
}	t_stack;

void	stack_clear(t_stack **lst);
void	stack_append(t_stack **lst, t_stack *new);
void	stack_push(t_stack **a, t_stack **b, char format);
void	stack_swap(t_stack **lst, char format);
void	stack_swap_both(t_stack **lst1, t_stack **lst2);
void	stack_rotate(t_stack **lst, char format);
void	stack_rotate_both(t_stack **lst1, t_stack **lst2);
void	stack_reverse_rotate(t_stack **lst, char format);
void	stack_reverse_rotate_both(t_stack **lst1, t_stack **lst2);
void	stack_sort(t_stack **lst1, t_stack **lst2);

t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *lst);
t_stack	*find_largest(t_stack **lst);
t_stack	*smallest_big_equal(t_stack *lst, int needle);
t_stack	*first_occur(t_stack *lst, t_stack *mid);

int		stack_count(t_stack *lst, t_stack *needle, char format);
int		stack_size(t_stack *lst);
int		stack_a_is_sorted(t_stack *lst);
int		stack_index(t_stack *lst, t_stack *needle);
int		find_smaller_than_mid(t_stack	*lst, t_stack *mid);

void	stack_sort_2(t_stack **lst1, t_stack **lst2);
void	stack_sort_b(t_stack **lst1, t_stack **lst2);
void	sort_stack_small_num(t_stack **lst1, t_stack **lst2);
void	stack_rotate_and_push(t_stack **lst1, t_stack **lst2, t_stack *needle);
void	sort_stack_3(t_stack **lst1);
#endif

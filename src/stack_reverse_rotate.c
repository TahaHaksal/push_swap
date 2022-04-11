#include "../include/Header.h"

void	stack_reverse_rotate_both(stack **lst1, stack **lst2)
{
	stack_reverse_rotate(lst1, ' ');
	stack_reverse_rotate(lst2, ' ');
	ft_printf("rrr\n");
}

void	stack_reverse_rotate(stack **lst, char format)
{
	stack	*tmp;

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

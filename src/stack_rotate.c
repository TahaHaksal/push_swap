#include "../include/Header.h"

void	stack_rotate_both(stack **lst1, stack **lst2)
{
	stack_rotate(lst1, ' ');
	stack_rotate(lst2, ' ');
	ft_printf("rr\n");
}

void	stack_rotate(stack **lst, char format)
{
	stack	*tmp;

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

#ifndef HEADER_H
# define HEADER_H
# include "libft.h"
# include "ft_printf.h"

typedef struct f_stack
{
	int				value;
	struct f_stack	*next;
}	stack;

void	stack_clear(stack **lst);
void	stack_append(stack **lst, stack *new);
void	stack_push(stack **a, stack **b, char format);
void	stack_swap(stack **lst, char format);
void	stack_swap_both(stack **lst1, stack **lst2);
void	stack_rotate(stack **lst, char format);
void	stack_rotate_both(stack **lst1, stack **lst2);
void	stack_reverse_rotate(stack **lst, char format);
void	stack_reverse_rotate_both(stack **lst1, stack **lst2);
void	stack_sort(stack **lst1, stack **lst2);

stack	*stack_new(int value);
stack	*stack_last(stack *lst);
stack	*find_largest(stack **lst);
stack	*smallest_big_equal(stack *lst, int needle);

int		stack_count(stack *lst, stack *needle, char format);
int		stack_size(stack *lst);
int		stack_a_is_sorted(stack *lst);
int		stack_index(stack *lst, stack *needle);
int		find_smaller_than_mid(stack	*lst, stack *mid);

void	stack_sort_2(stack **lst1, stack **lst2);
void	stack_sort_2_b(stack **lst1, stack **lst2, stack *needle);

#endif

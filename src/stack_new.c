#include "../include/Header.h"

stack	*stack_new(int value)
{
	stack	*tmp;

	tmp = malloc(sizeof(stack));
	tmp->value = value;
	tmp->next = NULL;
	return (tmp);
}

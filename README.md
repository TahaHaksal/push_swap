# push_swap
Write a sorting algorithm using stacks and with move restrictions

Allowed functions:
	-read,
	-write,
	-malloc,
	-free,
	-exit,
	-ft_printf

Description:
	Sort stacks using limited move pool
Requirements:
	-The program must display the smallest list of instructions possible to sort the stack a,
	-Instructions must be seperated by a new line,
	-The program should handle errors appropriately,
	Allowed moves:
		-sa(swap a): swap the first 2 elements in the stack a,
		-sb(swap b): swap the first 2 elements in the stack b,
		-ss: sa and sb at the same time,
		-pa: push the first element of b to a,
		-pb: push the first element of a to b,
		-ra(rotate a): move the first element of a to the end and shift the rest up,
		-rb(rotate b): move the first element of b to the end and shift the rest up,
		-rr: ra and rb at the same time,
		-rra(reverse rotate a): move the last element of a to beginning and shift the rest down,
		-rrb(reverse rotate b): move the last element of b to beginning and shift the rest down,
		-rrr: rra and rrb at the same time
	-Can't use global variables,
	-The program can't result in segmentation fault, Bus error, or abort in any condition.
Goal of the project:
	-Learn various sorting algorithms
	-Learn time complexity problems
	-Write your own sorting algorithm using restricted move pool

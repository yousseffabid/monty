#include "monty.h"
/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file*
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sum;
	pop(stack, line_number);
}

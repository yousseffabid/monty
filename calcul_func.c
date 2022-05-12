#include "monty.h"


/**
 * add - add top two elements and pop element
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum  = (*stack)->n +  (*stack)->next->n;
	(*stack)->next->n = sum;
	pop(stack, line_number);
}


/**
 * sub - subtract top two elements and pop first element
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int subtract = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	subtract = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = subtract;
	pop(stack, line_number);
}


/**
 * _div - divide top two elements and pop first element
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int division = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	division = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = division;
	pop(stack, line_number);
}


/**
 * _mod - computes the rest of the div
 * of top two elements and pop first element
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int modulo = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	modulo = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = modulo;
	pop(stack, line_number);
}

/**
 * mul -  multiplies  top two elements and pop first element
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int multiply = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	multiply = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = multiply;
	pop(stack, line_number);
}



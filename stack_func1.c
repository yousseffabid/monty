#include "monty.h"

/**
 * digits - checks if data is only composed of digits
 * @data: string to check
 * Return: 0 on failure or 1 on success
 */
int digits(char *data)
{
	unsigned int i;

	if (data == NULL)
		return (0);
	for (i = 0; data[i] != '\0'; i++)
	{
		if (data[0] == '-' && i == 0)
			continue;
		if (isdigit(data[i]) == 0)
			return (0);
	}
	return (1);
}


/**
 * push - add node at the end of double linked list.
 * @stack: pointer to the first node
 * @line_number: data to populate the node
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	(void)line_number;

	if (stack == NULL)
		return;
	if (!digits(DATA))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(DATA);
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}


/**
 * pop - removes the last element of a stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = NULL;
	free(ptr);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}



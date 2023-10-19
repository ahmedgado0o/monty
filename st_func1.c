#include "monty.h"


/**
 * a_t_s - Add node
 * @n_n: new node
 * @l: line number
 */
void a_t_s(stack_t **n_n, __attribute__((unused))unsigned int l)
{
	stack_t *tm;

	if (n_n == NULL || *n_n == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_n;
		return;
	}
	tm = head;
	head = *n_n;
	head->next = tm;
	tm->prev = head;
}


/**
 * p_s - Add node
 * @s: the stack.
 * @l_n: line number
 */
void p_s(stack_t **s, unsigned int l_n)
{
	stack_t *tm;

	(void) l_n;
	if (s == NULL)
		exit(EXIT_FAILURE);
	tm = *s;
	while (tm != NULL)
	{
		printf("%d\n", tm->n);
		tm = tm->next;
	}
}

/**
 * p_t - Add node
 * @s: the stack
 * @l_n: line number
 */
void pop_t(stack_t **s, unsigned int l_n)
{
	stack_t *tm;

	if (s == NULL || *s == NULL)
		errors_2(7, l_n);

	tm = *s;
	*s = tm->next;
	if (*s != NULL)
		(*s)->prev = NULL;
	free(tm);
}

/**
 * p_t - Print top
 * @s: the stack
 * @l_n: line number
 */
void p_t(stack_t **s, unsigned int l_n)
{
	if (s == NULL || *s == NULL)
		errors_2(6, l_n);
	printf("%d\n", (*s)->n);
}


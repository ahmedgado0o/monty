#include "monty.h"

/**
 * p_c - Print Ascii
 * @s: the stack.
 * @l_n: line number
 */
void p_c(stack_t **s, unsigned int l_n)
{
	int asci;

	if (s == NULL || *s == NULL)
		error_str(11, l_n);

	asci = (*s)->n;
	if (asci < 0 || asci > 127)
		error_str(10, l_n);
	printf("%c\n", asci);
}

/**
 * p_s - Print string.
 * @s: the stack.
 * @lln: line number
 */
void p_str(stack_t **s, __attribute__((unused))unsigned int lln)
{
	int asci;
	stack_t *tm;

	if (s == NULL || *s == NULL)
	{
		printf("\n");
		return;
	}

	tm = *s;
	while (tm != NULL)
	{
		asci = tm->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		tm = tm->next;
	}
	printf("\n");
}

/**
 * rotttl - Rotates
 * @s: the stack
 * @lln: line number
 */
void rotttl(stack_t **s, __attribute__((unused))unsigned int lln)
{
	stack_t *tm;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return;

	tm = *s;
	while (tm->next != NULL)
		tm = tm->next;

	tm->next = *s;
	(*s)->prev = tm;
	*s = (*s)->next;
	(*s)->prev->next = NULL;
	(*s)->prev = NULL;
}


/**
 * rotttr - Rotates
 * @s: the stack
 * @lln: line number
 */
void rotttr(stack_t **s, __attribute__((unused))unsigned int lln)
{
	stack_t *tm;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return;

	tm = *s;

	while (tm->next != NULL)
		tm = tm->next;

	tm->next = *s;
	tm->prev->next = NULL;
	tm->prev = NULL;
	(*s)->prev = tm;
	(*s) = tm;
}


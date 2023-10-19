#include "monty.h"

/**
 * no - nothing
 * @s: the stack
 * @l_n: line number
 */
void no(stack_t **s, unsigned int l_n)
{
	(void)s;
	(void)l_n;
}


/**
 * s_n - Swap
 * @s: the stack
 * @l_n: line number
 */
void s_n(stack_t **s, unsigned int l_n)
{
	stack_t *tm;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		errors_2(8, l_n, "swap");
	tm = (*s)->next;
	(*s)->next = tm->next;
	if (tm->next != NULL)
		tm->next->prev = *s;
	tm->next = *s;
	(*s)->prev = tm;
	tm->prev = NULL;
	*s = tm;
}

/**
 * a_n - Add to the stack
 * @s: the stack
 * @l_n: line number
 */
void a_n(stack_t **s, unsigned int l_n)
{
	int summ;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		errors_2(8, l_n, "add");

	(*s) = (*s)->next;
	summ = (*s)->n + (*s)->prev->n;
	(*s)->n = summ;
	free((*s)->prev);
	(*s)->prev = NULL;
}


/**
 * s_n - elements of the stack
 * @s: the stack
 * @l_n: line number
 */
void sub_n(stack_t **s, unsigned int l_n)
{
	int summ;

	if (s == NULL || *s == NULL || (*s)->next == NULL)

		errors_2(8, l_n, "sub");


	(*s) = (*s)->next;
	summ = (*s)->n - (*s)->prev->n;
	(*s)->n = summ;
	free((*s)->prev);
	(*s)->prev = NULL;
}


/**
 * d_n - elements of the stack
 * @s: the stack.
 * @l_n: line number
 */
void d_n(stack_t **s, unsigned int l_n)
{
	int summ;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		errors_2(8, l_n, "div");

	if ((*s)->n == 0)
		errors_2(9, l_n);
	(*s) = (*s)->next;
	summ = (*s)->n / (*s)->prev->n;
	(*s)->n = summ;
	free((*s)->prev);
	(*s)->prev = NULL;
}


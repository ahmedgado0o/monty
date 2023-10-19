#include "monty.h"

/**
 * m_n - elements of the stack
 * @s: the stack
 * @l_n: line number
 */
void m_n(stack_t **s, unsigned int l_n)
{
	int summ;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		errors_2(8, l_n, "mul");

	(*s) = (*s)->next;
	summ = (*s)->n * (*s)->prev->n;
	(*s)->n = summ;
	free((*s)->prev);
	(*s)->prev = NULL;
}


/**
 * mo_n - elements of the stack
 * @s: the stack
 * @l_n: line number
 */
void mo_n(stack_t **s, unsigned int l_n)
{
	int summ;

	if (s == NULL || *s == NULL || (*s)->next == NULL)

		errors_2(8, l_n, "mod");


	if ((*s)->n == 0)
		errors_2(9, l_n);
	(*s) = (*s)->next;
	summ = (*s)->n % (*s)->prev->n;
	(*s)->n = summ;
	free((*s)->prev);
	(*s)->prev = NULL;
}


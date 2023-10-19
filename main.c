#include "monty.h"
stack_t *he = NULL;

/**
 * main - main function
 * @argcc: counts argus
 * @argvv: argus
 * Return: always 0
 */

int main(int argcc, char *argvv[])
{
	if (argcc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	o_f(argvv[1]);
	f_n();
	return (0);
}

/**
 * c_n - start node
 * @num: Number of node
 * Return: NULL or success
 */
stack_t *c_n(int num)
{
	stack_t *nod;

	nod = malloc(sizeof(stack_t));
	if (nod == NULL)
		errors(4);
	nod->next = NULL;
	nod->prev = NULL;
	nod->n = num;
	return (nod);
}

/**
 * f_n - Free nodes
 */
void f_n(void)
{
	stack_t *tm;

	if (he == NULL)
		return;

	while (he != NULL)
	{
		tm = he;
		he = he->next;
		free(tm);
	}
}


/**
 * a_t_q - Add node
 * @n_n: new node
 * @l: l number
 */
void a_t_q(stack_t **n_n, __attribute__((unused))unsigned int l)
{
	stack_t *tm;

	if (n_n == NULL || *n_n == NULL)
		exit(EXIT_FAILURE);
	if (he == NULL)
	{
		he = *n_n;
		return;
	}
	tm = he;
	while (tm->next != NULL)
		tm = tm->next;

	tm->next = *n_n;
	(*n_n)->prev = tm;

}


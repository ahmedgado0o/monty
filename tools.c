#include "monty.h"

/**
 * opf - opens
 * @f_n: file name
 * Return:
 */

void opf(char *f_n)
{
	FILE *ffdd = fopen(f_n, "r");

	if (f_n == NULL || ffdd == NULL)
		errors(2, f_n);

	r_f(ffdd);
	fclose(ffdd);
}


/**
 * r_f - read file
 * @ffd: pointer
 * Return:
 */

void r_f(FILE *ffd)
{
	int l_n, f = 0;
	char *buf = NULL;
	size_t length = 0;

	for (l_n = 1; getline(&buf, &length, ffd) != -1; l_n++)
	{
		f = p_l(buf, l_n, f);
	}
	free(buf);
}


/**
 * p_l - Separates each line
 * @buf: line
 * @l_n: line num
 * @f:  stored format
 * Return: 0 if opcode or 1 if queue
 */

int p_l(char *buf, int l_n, int f)
{
	char *opc, *v;
	const char *d = "\n ";

	if (buf == NULL)
		errors(4);

	opc = strtok(buf, d);
	if (opc == NULL)
		return (f);
	v = strtok(NULL, d);

	if (strcmp(opc, "stack") == 0)
		return (0);
	if (strcmp(opc, "queue") == 0)
		return (1);

	f_f(opc, v, l_n, f);
	return (f);
}

/**
 * f_f - find functiob
 * @opc: op code
 * @v: argument
 * @f:  stored format
 * @l_nn: line
 * Return:
 */
void f_f(char *opc, char *v, int l_nn, int f)
{
	int iii;
	int fl;

	instruction_t f_l[] = {
		{"push", a_t_s},
		{"pall", p_s},
		{"pint", p_t},
		{"pop", pop_t},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opc[0] == '#')
		return;

	for (fl = 1, iii = 0; f_l[iii].opc != NULL; iii++)
	{
		if (strcmp(opc, f_l[iii].opc) == 0)
		{
			c_f(f_l[iii].f, opc, v, l_nn, f);
			fl = 0;
		}
	}
	if (fl == 1)
		errors(3, l_nn, opc);
}


/**
 * c_f - Calls function.
 * @function: Pointer to be called.
 * @opcc: string opcode.
 * @value: numeric value.
 * @l_nn: line numeber
 * @f: format speci
 */
void c_f(op_func function, char *opcc, char *value, int l_nn, int f)
{
	stack_t *n;
	int fl;
	int iii;

	fl = 1;
	if (strcmp(opcc, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			fl = -1;
		}
		if (value == NULL)
			errors(5, l_nn);
		for (iii = 0; value[iii] != '\0'; iii++)
		{
			if (isdigit(value[iii]) == 0)
				errors(5, l_nn);
		}
		n = c_n(atoi(value) * fl);
		if (f == 0)
			function(&n, l_nn);
		if (f == 1)
			a_t_q(&n, l_nn);
	}
	else
		function(&head, l_nn);
}


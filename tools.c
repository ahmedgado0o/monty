#include "monty.h"

/**
 * o_f - opens
 * @f_n: file name
 * Return:
 */

void o_f(char *f_n)
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
 * @opcode: op code
 * @v: argument
 * @f:  stored format
 * @l_nn: line
 * Return:
 */
void f_f(char *opcode, char *v, int l_nn, int f)
{
	int iii;
	int fl;

	instruction_t func_list[] = {
		{"push", a_t_s},
		{"pall", p_s},
		{"pint", p_t},
		{"pop", pop_t},
		{"nop", no},
		{"swap", s_n},
		{"add", a_n},
		{"sub", sub_n},
		{"div", d_n},
		{"mul", m_n},
		{"mod", mo_n},
		{"pchar", p_c},
		{"pstr", p_s},
		{"rotl", rotttl},
		{"rotr", rotttr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (fl = 1, iii = 0; func_list[iii].opcode != NULL; iii++)
	{
		if (strcmp(opcode, func_list[iii].opcode) == 0)
		{
			c_f(func_list[iii].f, opcode, v, l_nn, f);
			fl = 0;
		}
	}
	if (fl == 1)
		errors(3, l_nn, opcode);
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


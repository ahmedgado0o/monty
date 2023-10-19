#include "monty.h"

/**
 * errors - Prints error messages
 * @err: The error messeges\
 * Return: 
 */
void errors(int err, ...)
{
	va_list argu;
	char *oppp;
	int num_1;

	va_start(argu, err);
	switch (err)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argu, char *));
			break;
		case 3:
			num_1 = va_arg(argu, int);
			oppp = va_arg(argu, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num_1, oppp);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argu, int));
			break;
		default:
			break;
	}
	f_n();
	exit(EXIT_FAILURE);
}

/**
 * errors_2 - handle errs
 * @error_code: The errors
 * Return:
 */
void errors_2(int err, ...)
{
	va_list argu;
	char *oppp;
	int num_1;

	va_start(argu, err);
	switch (err)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argu, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argu, int));
			break;
		case 8:
			num_1 = va_arg(argu, unsigned int);
			oppp = va_arg(argu, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num_1, oppp);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argu, unsigned int));
			break;
		default:
			break;
	}
	f_n();
	exit(EXIT_FAILURE);
}

/**
 * error_str - errors
 * @err: The errors
 */
void error_str(int err, ...)
{
	va_list argu;
	int num_1;

	va_start(argu, err);
	num_1 = va_arg(argu, int);
	switch (err)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num_1);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num_1);
			break;
		default:
			break;
	}
	f_n();
	exit(EXIT_FAILURE);
}


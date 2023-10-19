#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void o_f(char *f_n);
int p_l(char *buf, int l_n, int f);
void r_f(FILE *ffd);
int len_chars(FILE *);
void f_f(char *opc, char *v, int l_nn, int f);

/*Stack operations*/
stack_t *c_n(int num);
void f_n(void);
void p_s(stack_t **s, unsigned int l_n);
void a_t_s(stack_t **n_n, __attribute__((unused))unsigned int l);
void a_t_q(stack_t **n_n, __attribute__((unused))unsigned int l);

void c_f(op_func function, char *opcc, char *value, int l_nn, int f);

void p_t(stack_t **s, unsigned int l_n);
void pop_t(stack_t **s, unsigned int l_n);
void no(stack_t **s, unsigned int l_n);
void s_n(stack_t **s, unsigned int l_n);

/*Math operations with nodes*/
void a_n(stack_t **s, unsigned int l_n);
void sub_n(stack_t **s, unsigned int l_n);
void d_n(stack_t **s, unsigned int l_n);
void m_n(stack_t **s, unsigned int l_n);
void mo_n(stack_t **s, unsigned int l_n);

/*String operations*/
void p_c(stack_t **s, unsigned int l_n);
void p_str(stack_t **s, __attribute__((unused))unsigned int lln);
void rotttl(stack_t **s, __attribute__((unused))unsigned int lln);

/*Error hanlding*/
void errors(int err, ...);
void errors_2(int err, ...);
void error_str(int err, ...);
void rotttr(stack_t **s, __attribute__((unused))unsigned int lln);

#endif


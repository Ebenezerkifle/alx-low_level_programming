#ifndef MONTY_H
#define MONTY_H

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;
typedef stack_t dlistint_t;

size_t print_dlistint(const dlistint_t *h);

#endif
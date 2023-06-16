#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    free_dlistint(head);
    return (EXIT_SUCCESS);
}
void free_dlistint(dlistint_t *head)
{
    if (head == NULL)
        return;
    free_dlistint(head->next);
    free(head);
}

size_t print_dlistint(const dlistint_t *h)
{
    size_t nodes = 0;

    if (h == NULL)
        return (0);

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        nodes++;
    }

    return (nodes);
}

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new;

    if (!head)
        return (NULL);

    new = malloc(sizeof(dlistint_t));
    if (!new)
        return (NULL);

    new->n = n;

    new->next = *head;
    new->prev = NULL;

    if (*head)
        (*head)->prev = new;

    *head = new;

    return (new);
}

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new;
    dlistint_t *temp = *head;

    if (!head)
        return (NULL);

    new = malloc(sizeof(dlistint_t));
    if (!new)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
    {
        new->prev = NULL;
        *head = new;
        return (new);
    }

    while (temp->next)
        temp = temp->next;

    temp->next = new;
    new->prev = temp;

    return (new);
}
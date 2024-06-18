#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked list
 * of integers in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a;

	/* check for NULL or an empty list */
	if (list == NULL || *list == NULL)
		return;

	/* Initializes the current pointer to the second node */
	a = (*list)->next;

	/* Traverse the list */
	while (a != NULL)
	{
		/* does insertion sort */
		while (a->prev != NULL && a->prev->n > a->n)
		{
			a->prev->next = a->next;
			/* Adjust the pointers */
			if (a->next != NULL)
				a->next->prev = a->prev;

			a->next = a->prev;
			a->prev = a->prev->prev;

			/* Update the pointers */
			if (a->prev != NULL)
				a->prev->next = a;
			else
				*list = a;

			a->next->prev = a;

			/* Print the list */
			print_list(*list);
		}

		a = a->next;

	}

}

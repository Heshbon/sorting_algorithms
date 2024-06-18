#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* function prototypes for bubble_sort */
void bubble_sort(int *array, size_t size);

/* function prototype for print_array */
void print_array(const int *array, size_t size);

/* function prototypes for insertion_sort */
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);

/* function prototype for selection_sort */
void selection_sort(int *array, size_t size);

/* function prototypes for quick_sort */
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int left, int right);
void swap(int *a, int *b);

#endif /* SORT_H */


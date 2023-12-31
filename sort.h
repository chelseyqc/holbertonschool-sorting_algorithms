#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

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

/* given functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* prototypes for tasks */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* extra functions for tasks */
void insert_sorted(listint_t **list, listint_t *node1, listint_t *node2);
void swap_int(int *array, int *first, int *second, size_t size);
int partition(int *array, int low, int high, size_t size);
void rec_sort(int *array, int low, int high, size_t size);

#endif

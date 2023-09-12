#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list of integers in
* ascending order using the insertion sort algorithm
* @list: the doubly linked list
*
* Return: void
*/
void insert_sorted(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == node2)
	{
		return;
	}
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
		node2->prev = node1->prev;
	}
	else
	{
		*list = node2;
		node2->prev = NULL;
	}
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
		node1->next = node2->next;
	}
	else
	{
		node1->next = NULL;
	}
	node1->prev = node2;
	node2->next = node1;
}

void insertion_sort_list(listint_t **list)
{
	listint_t *node1;
	listint_t *node2;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	node1 = *list;

	while (node1->next != NULL)
	{
		node2 = node1->next;
		if (node1->n > node2->n)
		{
			insert_sorted(list, node1, node2);
			print_list(*list);
			node1 = *list;
		}
		else
		{
			node1 = node1->next;
		}
	}
}

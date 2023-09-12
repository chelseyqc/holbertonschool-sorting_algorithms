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
	}
	else
	{
		*list = node2;
	}
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

void insertion_sort_list(listint_t **list)
{
	listint_t *key;
	listint_t *current;
	listint_t *prev;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	key = (*list)->next;

	while (key != NULL)
	{
		current = key;
		prev = key->prev;

		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = prev;
			}
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev != NULL)
			{
				prev->prev->next = current;
			}
			else
			{
				*list = current;
			}
			prev->prev = current;
			prev = current->prev;
		}
		key = key->next;
		print_list(*list);
	}
}

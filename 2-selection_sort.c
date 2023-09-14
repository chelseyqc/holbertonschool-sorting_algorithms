#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
* @array: the array to sort
* @size: the size of the array
*
* Return: voidd
*/
void selection_sort(int *array, size_t size)
{
	size_t current_index;
	size_t min_index;
	size_t next_index;
	int swap;

	current_index = 0;

	if (array == NULL)
	{
		return;
	}
	while (current_index < (size - 1))
	{
		min_index = current_index;
		next_index = current_index + 1;
		while (next_index < size)
		{
			if (array[min_index] > array[next_index])
			{
				min_index = next_index;
			}
			next_index = next_index + 1;
		}
		if (min_index != current_index)
		{
			swap = array[current_index];
			array[current_index] = array[min_index];
			array[min_index] = swap;
			print_array(array, size);
		}
		current_index = current_index + 1;
	}
}

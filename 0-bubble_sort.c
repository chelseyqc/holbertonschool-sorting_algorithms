#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order using the
* bubble sort algorithm
* @array: the array of integers
* @size: the size of the array
*
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t outer_index;
	size_t inner_index;
	int swapped;

	outer_index = 0;

	if (array == NULL)
	{
		return;
	}
	/* iterates over array except the last */
	while (outer_index < size - 1)
	{
		inner_index = 0;
		/* iterates over unsorted */
		while (inner_index < size - outer_index - 1)
		{
			/* comparing adjacent elements in array */
			if (array[inner_index] > array[inner_index + 1])
			{
				/* swapping if out of order */
				swapped = array[inner_index];
				array[inner_index] = array[inner_index + 1];
				array[inner_index + 1] = swapped;
				print_array(array, size);
			}
			/* moves to next one in inner loop */
			inner_index = inner_index + 1;
		}
		/* move to next one in outer loop */
		outer_index = outer_index + 1;
	}
}

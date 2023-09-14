#include "sort.h"

/**
* swap - swaps 2 elements in an array
* @array: the array to be checked
* @first: the first swapped
* @second: the second swapped
* @size: the size of the array
*
* Return: void
*/
void swap(int *array, int *first, int *second, size_t size)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
	print_array(array, size);
}

/**
* partition - find the pivot and put into position
* @array: input array
* @low: lowest's index
* @high: highest's index
* @size: size of the array
*
* Return: the pivot
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int ptr;
	int index;

	pivot = array[high];
	ptr = low - 1;
	index = low;

	while (index < high)
	{
		if (array[index] < pivot)
		{
			ptr = ptr + 1;
			if (ptr != index)
			{
				swap(array, &array[ptr], &array[index], size);
			}
		}
		index = index + 1;
	}
	if (array[ptr + 1] != pivot)
	{
		swap(array, &array[ptr + 1], &array[high], size);
	}
	return (ptr + 1);
}

/**
* rec_sort - sorts an array of integers with recursion
* @array: name of array
* @low: lowest's index
* @high: highest's index
* @size: the size of the array
*
* Return: void
*/
void rec_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		rec_sort(array, low, (pivot - 1), size);
		rec_sort(array, (pivot + 1), high, size);
	}
}

/**
* quick_sort - sorts an array of integers in ascending order using the
* quick sort algorithm
* @array: the array to be sorted
* @size: the size of the array
*
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
	{
		return;
	}
	if (size < 2)
	{
		return;
	}
	rec_sort(array, 0, (size - 1), size);
}

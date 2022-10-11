#include <stdio.h>
#include "sort.h"
#include <stddef.h>

/**
 * selection_sort - sorts an array using the selection sort method
 * @array: Array to be sorted
 * @size: Size of array to be sorted
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min == i)
			continue;
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
		print_array(array, size);
	}
}

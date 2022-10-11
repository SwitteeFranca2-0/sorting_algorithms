#include "sort.h"
#include <stddef.h>


/**
 * shell_sort - sort an array using shell sort algorithm with knuth sequence
 * @arr: array to be sorted
 * @size: length of the array
 * Return: Nothing
 */


void shell_sort(int *arr, size_t size)
{
	size_t gap = 1;

	if (!arr || !size || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		size_t i = gap;

		while (i < size)
		{
			size_t j = i;

			while (j >= gap && arr[j - gap] > arr[j])
			{
				int tmp = arr[j];

				arr[j] = arr[j - gap];
				arr[j - gap] = tmp;

				j -= gap;
			}

			i++;
		}

		print_array(arr, size);
	}
}

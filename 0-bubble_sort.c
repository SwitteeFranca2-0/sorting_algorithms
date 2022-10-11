#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stddef.h>

/**
 * bubble_sort - bubble sort
 * @array: array
 * @size: size
 * Return: none.
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i;
	int status = 1;

	if (!array || !size || size < 2)
		return;

	while (status == 1)
	{
		status = 0;
		i = 0;
		while (i < size)
		{
			if (array[i] > array[i + 1])
			{
				status = 1;
				break;
			}
			i++;
		}

		if (status == 1)
		{
			for (i = 0; i < size; i++)
			{
				if (array[i] > array[i + 1])
				{
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					print_array(array, size);
				}
			}
		}
	}
}

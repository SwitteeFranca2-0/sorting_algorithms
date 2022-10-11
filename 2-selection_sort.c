#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stddef.h>

/**
 * selection_sort - selection sort
 * @array: array
 * @size: size
 * Return: none.
 */
void selection_sort(int *array, size_t size)
{
	int tmp, num, pos, suc = 0;
	size_t i;
	int status = 1;

	if (!array || !size || size < 2)
		return;

	while (status == 1)
	{
		num = array[suc];
		for (i = suc; i < size; i++)
		{
			if (num >= array[i])
			{
				num = array[i];
				pos = i;
			}
		}
		tmp = array[suc];
		array[suc] = num;
		array[pos] = tmp;
		suc += 1;
		print_array(array, size);
		status = 0;
		for (i = 0; i < size; i++)
		{
			if (i != size - 1 && array[i] >= array[i + 1])
			{
				status = 1;
			}
		}
	}
}

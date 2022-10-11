#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - counting sort
 * @array: array
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	int *tmp, *arr, i, max = 0;

	if (!array || size < 2 || !size)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	tmp = malloc(sizeof(int) * (max + 1));
	for (i = 0; i < max + 1; i++)
		tmp[i] = 0;
	arr = malloc(sizeof(int) * size);
	if (tmp == NULL || arr == NULL)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (tmp[array[i]] != 0)
		{
			tmp[array[i]] += 1;
			continue;
		}
		tmp[array[i]] = 1;
	}
	for (i = 0; i < max + 1; i++)
	{
		if (i != 0)
			tmp[i] = tmp[i - 1] + tmp[i];
	}
	print_array(tmp, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		arr[tmp[array[i]] - 1] = array[i];
		tmp[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = arr[i];
	free(tmp);
	free(arr);
}

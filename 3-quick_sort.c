#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void quick(int *array, size_t start, size_t end, size_t size);
int partition(int *array, size_t start, size_t end, size_t size);

/**
 * partition - partition the array.
 * @array: array.
 * @start: start.
 * @end: end.
 * @size: size
 * Return: int.
 */
int partition(int *array, size_t start, size_t end, size_t size)
{
	size_t pivot, i, num, tmp;

	pivot = array[end];
	num = start - 1;
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			num += 1;
			tmp = array[num];
			array[num] = array[i];
			array[i] = tmp;

			if (array[i] != array[num])
				print_array(array, size);
		}
	}

	tmp = array[num + 1];
	array[num + 1] = array[end];
	array[end] = tmp;
	if (array[end] != array[num + 1])
		print_array(array, size);

	return (num + 1);
}

/**
 * quick - quick sort.
 * @array: array.
 * @start: start.
 * @end: end.
 * @size: size.
 */
void quick(int *array, size_t start, size_t end, size_t size)
{
	size_t pInd;

	if (start < end)
	{
		pInd = partition(array, start, end, size);
		quick(array, start, pInd - 1, size);
		quick(array, pInd + 1, end, size);
	}
}
/**
 * quick_sort - quick sort.
 * @array: array.
 * @size: size.
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quick(array, 0, size - 1, size);
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge_divide(int *arr, size_t size, size_t start, size_t end, int *new);
void merge_conquer(int *arr, int l_st, int r_st, int r_ed, int *new);
void merge_print(int *arr, int start, int end, char *string);
/**
 * merge_print - merge print.
 * @arr: arr.
 * @start: start.
 * @end: end.
 * @string: string.
 */
void merge_print(int *arr, int start, int end, char *string)
{
	int i;

	printf("[%s]: ", string);
	for (i = start; i < end; i++)
	{
		printf("%i", arr[i]);
		if (i != end - 1)
			printf(", ");

	}
	printf("\n");
}
/**
 * merge_conquer - merge conquer.
 * @arr: arr.
 * @l_st: left start position.
 * @r_st: right start position.
 * @r_ed: right end position.
 * @new: new array.
 */
void merge_conquer(int *arr, int l_st, int r_st, int r_ed, int *new)
{
	int l, r, i;

	l = i = l_st;
	r = r_st;


	while (l < r_st && r < r_ed)
	{
		if (arr[l] >= arr[r])
		{
			new[i] = arr[r];
			i++;
			r++;
			continue;
		}
		if (arr[r] > arr[l])
		{
			new[i] = arr[l];
			i++;
			l++;
		}
	}

	printf("Merging...\n");
	merge_print(arr, l_st, r_st, "left");
	merge_print(arr, r_st, r_ed, "right");

	while (l < r_st)
		new[i++] = arr[l++];
	while (r < r_ed)
		new[i++] = arr[r++];
	merge_print(new, l_st, r_ed, "Done");
	for (i = l_st; i < r_ed; i++)
		arr[i] = new[i];
}
/**
 * merge_divide - merge divide.
 *
 * @arr: arr.
 * @size: size.
 * @start: start.
 * @end: end.
 * @new: new.
 */
void merge_divide(int *arr, size_t size, size_t start, size_t end, int *new)
{
	size_t left, right;

	if (size < 2)
		return;
	left = size / 2;
	right = size - left;
	merge_divide(arr, left, start, start + left, new);
	merge_divide(arr, right, start + left, end, new);
	merge_conquer(arr, start, start + left, end, new);

}
/**
 * merge_sort - merge sort
 *
 * @array: array.
 * @size: size.
 */
void merge_sort(int *array, size_t size)
{
	int *new_array;

	if (!array || size < 0)
		return;
	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
		return;
	merge_divide(array, size, 0, size, new_array);
}

#include "sort.h"
#include <stdio.h>

/**
 * swap - swap integers at positions `i` and `j` in `array`
 * @array: array to swap positions
 * @i: left index
 * @j: right index
 */
void swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * partition - partition subarray of `array` around pivot using
 * Hoare method (always choose right element).
 * @array: array to partition
 * @left: left end of subarray
 * @right: right end of subarray
 * @size: size of array
 * Return: index of pivot after it has been sorted
 */
int partition(int *array, int left, int right, size_t size)
{
	int i, j, pivot;

	pivot = array[right];
	i = left - 1;
	j = right - 1;
	while (1)
	{
		for (i++; i < right; i++)
		{
			if (array[i] > pivot)
				break;
		}
		for (; j >= i; j--)
		{
			if (array[j] <= pivot)
			{
				swap(array, i, j);
				print_array(array, size);
				break;
			}
			if (j == i)
			{
				swap(array, i, right);
				print_array(array, size);
				return (i);
			}
		}
		if (i == right)
			break;
	}
	return (i);
}

/**
 * _quick_sort_hoare - recursively partition array until it is fully sorted
 * @array: array to sort
 * @left: left side of subarray for recursion
 * @right: right side of subarray for recursion
 * @size: size of array
 */
void _quick_sort_hoare(int *array, int left, int right, size_t size)
{
	int p;

	if (left < right)
	{
		p = partition(array, left, right, size);
		_quick_sort_hoare(array, left, p - 1, size);
		_quick_sort_hoare(array, p + 1, right, size);
	}
}

/**
 * quick_sort_hoare - wrapper around recursive quicksort function
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quick_sort_hoare(array, 0, (int)(size - 1), size);
}

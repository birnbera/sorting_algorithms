#include <stdlib.h>
#include "sort.h"

#include <stdio.h>

/**
 * counting_sort - Counting sort
 * @array: array to evaluate
 * @size: size of array
 * Return: None
 * Note: Most of it works, except for the last count[10]
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, oldCount = 0, *output, *count;
	size_t i, k = 0;

	if (array == NULL || size <= 1)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	k = max;
	count = malloc((k + 1) * sizeof(count));
	if (count == NULL)
		return;
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		output[i] = 0;
	for (i = 0; i < size ; i++)
		count[array[i]]++;
	for (i = 1; i <= k; i++)
	{
		oldCount = count[i - 1];
		count[i] = oldCount + count[i];
	}
	print_array((const int *)count, k + 1);
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}

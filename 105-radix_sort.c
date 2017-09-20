#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#define NUMDIGIT 10

/**
 * radix_sort - sorts data using Radix and prints it out
 * @array: data to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t max, digit, divisor = 1, base10 = 0, z, mult,  *output;
	size_t *count, i, j, item, oldCount;

	if ((array == NULL) || (size < 2))
		return;
	count = malloc(sizeof(size_t) * NUMDIGIT);
        if (count == NULL)
                return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
		output[i] = 0;
	for (i = 0; i < NUMDIGIT; i++)
		count[i] = 0;

	max = array[0];
	/* init arrays and find max array element */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/* Find largest power of 10 in max number */
	for (mult = 1; max > mult; mult *= 10, base10++)
		;

	/* Calc significant digits */
	for (z = 0; z < base10; z++)
	{
		for (i = 0; i < size; i++)
		{
			digit = (array[i] / divisor) % 10;
			count[digit]++;
		}
		for (i = 1; i < NUMDIGIT; i++)
		{
			oldCount = count[i - 1];
			count[i] = oldCount + count[i];
		}
		printf("COUNT:");
		for (i = 0; i < NUMDIGIT; i++)
			printf("%lu ", count[i]);
		printf("\n");
		for (i = size; i > 0; i--)
		{
			digit = (array[i - 1] / divisor) % 10;
			output[count[digit] - 1] = array[i - 1];
			count[digit]--;
		}

		for (i = 0; i < size; i++)
		{
			array[i] = output[i];
			output[i] = 0;
		}
		for (i = 0; i < NUMDIGIT; i++)
			count[i] = 0;
		print_array(array, size);
		divisor *= 10;
	}

	/*free(count);
	  free(output);*/
}

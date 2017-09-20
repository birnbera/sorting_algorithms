#include "sort.h"
#include <stdio.h>

void _bitonicMerge(int *array, size_t low, size_t cnt, size_t dir);

void _bitonicSort(int *array, size_t low, size_t cnt, size_t dir)
{
	size_t k = cnt / 2;

	printf("%s [%lu/%lu] (%s):\n",
	       "Merging",
	       cnt, 16UL,
	       dir ? "UP" : "DOWN");
	print_array(array + low, cnt);
	if (cnt > 1)
	{
		_bitonicSort(array, low, k, 1);
		_bitonicSort(array, low + k, k, 0);
		_bitonicMerge(array, low, cnt, dir);
	}
}

void _bitonicMerge(int *array, size_t low, size_t cnt, size_t dir)
{
	size_t i, k = cnt / 2;
	int tmp;

	if (cnt >= 1)
	{
		for (i = 0; i < low + k; i++)
		{
			if (!(dir ^ (array[i] > array[i + k])))
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
				printf("%s [%lu/%lu] (%s):\n",
				       dir ? "Merging" : "Result",
				       low, cnt,
				       dir ? "UP" : "DOWN");
				print_array(array + low, cnt);
			}
		}
		_bitonicMerge(array, low, k, dir);
		_bitonicMerge(array, low + k, k, dir);
	}
}

void bitonic_sort(int *array, size_t size)
{
	_bitonicSort(array, 0, size, 1);
}

#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 * @array: array being sorted
 * @size: size of the array
 */

static void swap(int *a, int *b, int *array, size_t size)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
 * lomuto_partition - partitions an array using Lomuto scheme
 * @array: array to partition
 * @size: size of the array
 * @low: starting index of partition
 * @high: ending index of partition (pivot)
 *
 * Return: final index of the pivot
 */

static int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
				swap(&array[i], &array[j], array, size);
		}
	}

	if (i + 1 != high)
		swap(&array[i + 1], &array[high], array, size);

	return (i + 1);
}

/**
 * quick_sort_rec - recursively sorts partitions of an array
 * @array: array to sort
 * @size: size of the array
 * @low: starting index
 * @high: ending index
 */

static void quick_sort_rec(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, size, low, high);
		quick_sort_rec(array, size, low, p - 1);
		quick_sort_rec(array, size, p + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers using Quick sort
 * @array: array to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, size, 0, (int)size - 1);
}

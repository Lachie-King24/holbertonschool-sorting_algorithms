#include "sort.h"

/**
 * selection_sort - sort array of int in asc order. use select sort
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t count1, count2, min_idx;

	if (!array || size < 2)
		return;

	for (count1 = 0; count1 < size - 1; count1++)
	{
		min_idx = count1;
		for (count2 = count1 + 1; count2 < size; count2++)
		{
			if (array[count2] < array[min_idx])
				min_idx = count2;
		}

		if (min_idx != count1)
		{
			temp = array[count1];
			array[count1] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}

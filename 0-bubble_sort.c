#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in asc order
 * @array: array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t count;
	int temp;
	bool check = false;

	if (!array || size < 2)
		return;

	while (!check)
	{
		check = true;
		for (count = 0; count < size - 1; count++)
		{
			if (array[count] > array[count + 1])
				{
					temp = array[count];
					array[count] = array[count + 1];
					array[count + 1] = temp;
					check = false;

					print_array(array, size);
				}
		}
	}
}

#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int index_min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		index_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index_min])
			{
				index_min = j;
			}
		}
		if (array[i] != array[index_min])
		{
			/*Swap */
			tmp = array[index_min];
			array[index_min] = array[i];
			array[i] = tmp;

			print_array(array, size);
		}
	}
}

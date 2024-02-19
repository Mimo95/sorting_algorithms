#include "sort.h"

/**
 * quicksort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void quicksort(int *array, size_t size, int low, int high)
{
	int pivt;

	if (low < high)
	{
		pivt = partition(array, size, low, high);
		quicksort(array, size, low, pivt - 1);
		quicksort(array, size, pivt + 1, high);
	}
}
/**
 * partition - Order a subset of an array of integers according to
 *             the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int above, tmp, i;

	pivot = array[high];
	above = low;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			if (i != above)
			{
				tmp = array[i];
				array[i] = array[above];
				array[above] = tmp;
				print_array(array, size);
			}
		above++;
		}
	}
	if (array[above] > pivot)
	{
		tmp = array[above];
		array[above] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (above);
}
/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
	{
		return;
	}
	quicksort(array, size, 0, size - 1);
}

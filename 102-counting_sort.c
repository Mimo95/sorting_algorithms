#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
    int *sorted_array, i, max_array, *count_array;

    if (size < 2 || array == NULL)
		return;

    max_array = array[0];
    for(i = 1; i < (int)size; i++)
    {
        if (array[i] > (int)max_array)
        {
            max_array = array[i];
        }
    }
    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
		return;
    count_array = malloc(sizeof(int) * (max_array + 1));
    if (count_array == NULL)
	{
		free(sorted_array);
		return;
	}
    for(i = 0; i <= max_array; i++)
    {
        count_array[i] = 0;
    }
    for(i = 0; i < (int)size; i++)
    {
        count_array[array[i]]++;
    }
    for(i = 0; i <= max_array; i++)
    {
        count_array[i] += count_array[i - 1];
    }
    print_array(count_array, max_array + 1);

    for(i = size - 1; i >= 0; i--)
    {
        count_array[array[i]]--;
        sorted_array[count_array[array[i]]] = array[i];
    }
    for (i = 0; i < (int)size; i++)
    {
        array[i] = sorted_array[i];
    }
    free(sorted_array);
	free(count_array);
}

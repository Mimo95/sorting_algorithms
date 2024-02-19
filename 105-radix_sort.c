#include "sort.h"

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */

void radix_sort(int *array, size_t size)
{
    int i, *sorted_array, max_array, sig;

    if (size < 2)
		return;

    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
	    return;

    max_array = array[0];
    for(i = 1; i < (int)size; i++)
    {
        if (array[i] > (int)max_array)
        {
            max_array = array[i];
        }
    }
    for (sig = 1; max_array / sig > 0; sig *= 10)
    {
        radix_counting_sort(array, size, sig, sorted_array);
        print_array(array, size);
    }
    free(sorted_array);
}
/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @sorted_array: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *sorted_array)
{
    int i;
    int count_array[10] = {0};

        for(i = 0; i < (int)size; i++)
        {
            count_array[(array[i] / sig) % 10]++;
        }
        for(i = 0; i < 10; i++)
        {
            count_array[i] += count_array[i - 1];
        }

        for(i = size - 1; i >= 0; i--)
        {
            count_array[(array[i] / sig) % 10]--;
            sorted_array[count_array[(array[i] / sig) % 10]] = array[i];
        }
        for (i = 0; i < (int)size; i++)
        {
            array[i] = sorted_array[i];
        }    
}

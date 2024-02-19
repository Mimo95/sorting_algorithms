#include "sort.h"

/**
 * MergeSort - Sort a subarray of integers.
 * @array: A subarray of an array of integers to sort.
 * @array_sort: A buffer to store the sorted subarray.
 * @index_beg: The front index of the array.
 * @index_middle: The middle index of the array.
 * @index_end: The back index of the array.
 */

void MergeSort(int *array, int *array_sort, size_t index_beg, size_t index_middle, size_t index_end)
{
    size_t i, j, k = 0;
    
    printf("Merging...\n[left]: ");
	print_array(array + index_beg, index_middle - index_beg);

	printf("[right]: ");
	print_array(array + index_middle, index_end - index_middle);

    for (i = index_beg, j = index_middle; i < index_middle && j < index_end; k++)
		array_sort[k] = (array[i] < array[j]) ? array[i++] : array[j++];

    while(i < index_middle)
    {
        array_sort[k++] = array[i];
        i++;
    }
    while(j < index_end)
    {
        array_sort[k++] = array[j];
        j++;
    }
	for (i = index_beg, k = 0; i < index_end; i++)
		array[i] = array_sort[k++];
 
    printf("[Done]: ");
	print_array(array + index_beg, index_end - index_beg);
}

/**
 * mergeSortTopDownSplit - Implement the merge sort algorithm through recursion.
 * @array: A subarray of an array of integers to sort.
 * @array_sort: A buffer to store the sorted result.
 * @index_beg: The front index of the subarray.
 * @index_end: The back index of the subarray.
 */
void mergeSortTopDownSplit(int *array, int *array_sort, size_t index_beg, size_t index_end)
{
    size_t index_Middle;

    if (index_end - index_beg <= 1)                     
        return; 

    index_Middle = (index_end + index_beg) / 2;
    mergeSortTopDownSplit(array, array_sort, index_beg, index_Middle);
    mergeSortTopDownSplit(array, array_sort, index_Middle, index_end);
    MergeSort(array, array_sort, index_beg, index_Middle, index_end);
    
}
/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
    int *array_sort;
    size_t i;

    if (size < 2 || array == NULL)
    {
        return;
    }
    array_sort = malloc(sizeof(int) * size);
    if (array_sort == 0)
    {
        return;
    }
    for (i = 0; i < size; i++)
    {
        array_sort[i] = array[i];
    }

    mergeSortTopDownSplit(array, array_sort, 0, size);
    free(array_sort);
}

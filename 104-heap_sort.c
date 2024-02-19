#include "sort.h"

/**
 * Heap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @i: The root node of the binary tree.
 */

void Heap(int *array, size_t size, size_t base, size_t i)
{
    size_t max_i, child1, child2;
    int tmp;

    child1 = 2 * i + 1;
    child2 = 2 * i + 2;
    max_i = i;


    if(child1 < base && array[child1] > array[max_i])
    {
        max_i = child1;
    }
    if(child2 < base && array[child2] > array[max_i])
    {
        max_i = child2;
    }
    if(max_i != i)
    {
        tmp = array[i];
        array[i] = array[max_i];
        array[max_i] = tmp;
        print_array(array, size);
        Heap(array, size, base, max_i);
        
    }
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
    int i, tmp;

    if (size < 2 || array == NULL)
    {
        return;
    }

    for (i = size / 2 - 1; i >= 0; i--)
    {
        Heap(array, size, size, i);
    }
    for (i = size - 1; i > 0; i--)
    {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        print_array(array, size);
        Heap(array, size, i, 0);
    }
}

#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
listint_t *create_listint(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
size_t dlistint_len(const listint_t *h);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
size_t partition(int *array, size_t size, size_t low, size_t high);
void quicksort(int *array, size_t size, size_t low, size_t high);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void mergeSortTopDownSplit(int *array, int *array_sort, size_t index_beg, size_t index_end);
void MergeSort(int *array, int *array_sort, size_t index_beg, size_t index_Middle, size_t index_end);
void heap_sort(int *array, size_t size);
void Heap(int *array, size_t size, size_t base, size_t i);
void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int sig, int *sorted_array);

#endif
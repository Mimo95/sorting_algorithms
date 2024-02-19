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
int partition(int *array, size_t size, int low, int high);
void quicksort(int *array, size_t size, int low, int high);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void Heap(int *array, size_t size, size_t base, size_t i);
void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int sig, int *sorted_array);

#endif

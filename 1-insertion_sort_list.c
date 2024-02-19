#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr;
	listint_t *ptr2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ptr = (*list)->next;

	while (ptr != NULL)
	{
		ptr2 = ptr->prev;
		while (ptr2 != NULL && ptr->n < ptr2->n)
		{
			/*Swap nodes*/
			if (ptr->next != NULL)
				ptr->next->prev = ptr2;
			ptr2->next = ptr->next;
			ptr->next = ptr2;
			ptr->prev = ptr2->prev;
			ptr2->prev = ptr;
			if (ptr->prev != NULL)
				ptr->prev->next = ptr;
			else
				*list = ptr;
			ptr2 = ptr->prev;

			print_list(*list);
		}
		ptr = ptr->next;
	}
}

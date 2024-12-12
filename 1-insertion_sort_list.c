#include "sort.h"
/**
 * insertion_sort_list - Function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Structure
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		insertion_point = current->prev;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			insertion_point->next = current->next;
			if (current->next != NULL)
				current->next->prev = insertion_point;
			current->prev = insertion_point->prev;
			current->next = insertion_point;
			if (insertion_point->prev != NULL)
				insertion_point->prev->next = current;
			else
				*list = current;
			insertion_point->prev = current;
			print_list(*list);
			insertion_point = current->prev;
		}
		current = next;
	}
}

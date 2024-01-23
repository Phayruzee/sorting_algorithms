#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using insertion sort
 *
 * @list: a pointer to the head node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *present = NULL, *future = NULL, *tmp = NULL;

	if (list == NULL || (*list)->next == NULL)
		return;

	present = (*list)->next;

	while (present)
	{
		future = present->next;
		tmp = present;

		while (tmp->prev && tmp->prev->n > tmp->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;
			print_list(*list);
		}
		present = future;
	}
}

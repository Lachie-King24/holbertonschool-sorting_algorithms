#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly link list asc order, use insert alg
 * @list: pointer to a pointer of a list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp;

	if (!list || !*list)
		return;

	node = (*list)->next;



	while (node)
	{
		temp = node;

		while (temp->prev && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;

			if (temp->next)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			temp->next->prev = temp;

			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);
		}
		node = node->next;
	}
}

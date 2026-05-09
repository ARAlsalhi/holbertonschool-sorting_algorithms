#include "sort.h"

/**
 * swap_nodes - swaps a node with its previous node
 * @list: pointer to the head of the list
 * @node: node to swap with its previous node
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev;
	listint_t *next;

	prev = node->prev;
	next = node->next;

	if (prev->prev != NULL)
		prev->prev->next = node;
	else
		*list = node;

	node->prev = prev->prev;
	node->next = prev;
	prev->prev = node;
	prev->next = next;

	if (next != NULL)
		next->prev = prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, current);
			print_list(*list);
		}

		current = next;
	}
}

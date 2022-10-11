#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - insertion sort.
 * @list: list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *loop, *tmp, *nxt, *prv, *pres;

	if (!list || !(*list))
		return;

	loop = (*list)->next;

	while (loop)
	{
		tmp = loop;
		while (tmp && tmp->prev && tmp->prev->n > tmp->n)
		{
			pres = tmp;
			prv = tmp->prev;
			nxt = tmp->next;
			pres->next = prv;
			pres->prev = prv->prev;
			if (prv->prev)
				prv->prev->next = pres;
			prv->prev = pres;
			prv->next = nxt;
			if (nxt)
				nxt->prev = prv;
			if (prv == *list)
				*list = prv->prev;
			print_list(*list);
			tmp = prv->prev;
		}
		loop = loop->next;
	}
}

#include <stdio.h>
#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - cocktail sort.
 * @list: list. 
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *prv, *nxt, *pres;
	int n = 1;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	while (n == 1)
	{
		tmp = *list;
		n = 0;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				pres = tmp;
				nxt = tmp->next;
				prv = tmp->prev;
				pres->next = nxt->next;
				pres->prev = nxt;
				if (nxt->next)
					nxt->next->prev = pres;
				nxt->next = pres;
				nxt->prev = prv;
				if (prv)
					prv->next = nxt;
				if (pres == *list)
					*list = pres->prev;
				n = 1;
				print_list(*list);
			}
			else
			{
				tmp = tmp->next;
			}
		}
		while (tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				pres = tmp;
				prv = tmp->prev;
				nxt = tmp->next;

				pres->next = prv;
				pres->prev = prv->prev;
				if (pres->prev)
					pres->prev->next = pres;

				prv->next = nxt;
				prv->prev = pres;
				if(nxt)
					nxt->prev = prv;

				if (prv == *list)
					*list = prv->prev;
				n = 1;
				print_list(*list);
			}
			else
			{
				tmp = tmp->prev;
			}
		}
	}
}
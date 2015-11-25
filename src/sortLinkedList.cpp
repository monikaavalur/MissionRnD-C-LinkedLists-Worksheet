/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) 
{
	if (head==NULL)
	return NULL;
	node *new1 ,*count;
	new1 = head;
	for (; new1->next != NULL; new1 = new1->next)
	{
		for (count = new1->next; count != NULL; count = count->next)
		{
			if (new1->num > count->num)
			{
				int temp = new1->num;
				new1->num = count->num;
				count->num= temp;
			}
		}
	}
	return head;
}
/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};
void swap(struct node *Arr,struct node *Arr1);
void sll_012_sort(struct node *head)
{
	int index1;
	struct node *ptr;
	ptr = head;
	struct node *ptr1 = NULL;
	if (ptr == NULL)
		return;
	do
	{
		index1 = 0;
		ptr = head;
		while (ptr->next != ptr1)
		{
			if (ptr->data > ptr->next->data)
			{
				swap(ptr, ptr->next);
				index1 = 1;
			}
			ptr = ptr->next;
		}
		ptr1 = ptr;
	} while (index1);
}
void swap(struct node *Arr, struct node *Arr1)
{
	int temp = Arr->data;
	Arr->data = Arr1->data;
	Arr1->data = temp;
}
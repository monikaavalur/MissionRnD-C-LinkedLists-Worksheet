/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 1)
		return NULL;
		else
		{
			struct node *start;
			struct node *current_node;
			struct node *previous_node;
			current_node = start = head;
			int len = 0;
			while (current_node!=NULL)
			{
				current_node = current_node->next;
				len++;
			}
			int position;
			int temp = 1;
			for (position=1;position<=len;position++)
			{
				if (position%K==0)
				{
					int index = temp;
					current_node = start;
					while (index < position)
					{
						previous_node = current_node;
						current_node = current_node->next;
						index++;
					}
					start = current_node->next;
					previous_node->next = current_node->next;
					temp = position + 1;
				}
			}
			return head;
		}
	}

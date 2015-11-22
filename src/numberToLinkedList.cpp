/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N)
{
	node *new_node, *current, *start;
	start = NULL;
	if (N == 0)
	{
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node->num = N;
			new_node->next = NULL;
				start = new_node;
				current = new_node;
	}
	else
	{
		if (N < 0)
			N = -N;
		int num = N;
		int Arr[100], length = 0, index;
		while (N != 0)
		{
			length++;
			N = N / 10;
		}
		index = length - 1;
		while (num != 0)
		{
			Arr[index] = num % 10;
			num = num / 10;
			index--;
		}
		index = 0;
		do
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node->num = Arr[index];
			new_node->next = NULL;

			if (start == NULL)
			{
				start = new_node;
				current = new_node;
			}
			else
			{
				current->next = new_node;
				current = new_node;
			}
			index++;
		} while (index != length);
	}
		return start;
}

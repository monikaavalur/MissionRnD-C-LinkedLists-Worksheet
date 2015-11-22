/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>
#include<math.h>
struct node {
	int digit1;
	int digit2;
	struct node *next;
};

int convert_sll_2digit_to_int(struct node *head)
{
	struct node *ptr;
	ptr = head;
	int Arr[100],count=0,index=0;
	if (ptr == NULL)
		return NULL;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	ptr = head;
	do
	{
		Arr[index] = ptr->digit1;
		index++;
		Arr[index] = ptr->digit2;
		index++;
		ptr = ptr->next;
	} while (ptr!=NULL);

	int len= index;
	Arr[len] = '\0';
	long int num=0, product;
	for (index = 0; index<len; index++)
	{
		product = 10;
		while (Arr[index] >= product)
			product *= 10;
		num *= product;
		num += Arr[index];
	}
	return num;
}

/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "header_file.h"
Status do_addition(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3){
	int carry=0,sum=0,res=0,car=0;

	Dlist *temp1 = tail1;
	Dlist *temp2 = tail2;

	while(temp1 != NULL || temp2 != NULL)
	{
		
		res = (temp1->data) + (temp2->data) + carry;
		car = res / 10;
		res = res % 10;
		sum =  res;

		add_result(head3,tail3,sum);

		temp1 = temp1->prev;
		temp2 = temp2->prev;
		carry = car;
	}
	if(carry != 0)
	{
		add_result(head3,tail3,carry);
	}

	return success;
}
Status add_result(Dlist **headR,Dlist **tailR,int sum)
{
	// INSERT AT FIRST methodology
	Dlist* new = malloc(sizeof(Dlist));
	if(new == NULL)
	{
		printf("Memory allocation failed\n");
		return failure;
	}

	new->data = sum;
	new->prev = NULL;
	new->next = NULL;
	if( *headR == NULL)
	{
		*headR = new;
		*tailR = new;
	}
	else
	{
		new->next = *headR;
		(*headR)->prev = new;
		*headR = new;
	}
	return success;
}


/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/



#include "header_file.h"
extern int negative_flag;
Status do_mul(Dlist* head1,Dlist* tail1,Dlist* head2,Dlist* tail2,Dlist** headR,Dlist** tailR)
{
	int result = 0,count= 0,mult = 0,carry = 0;
	Dlist* temp1 = tail1;
	Dlist* temp2 = tail2;

	Dlist* result_head1 = NULL;
	Dlist* result_tail1 = NULL;
	Dlist* result_head2 = NULL;
	Dlist* result_tail2 = NULL;
	while(temp2)
	{
		carry=0;
		temp1 = tail1;
		while(temp1)
		{
			mult =  carry;
			for(int i = 0;i<temp2->data;i++) //run loop temp2 data times 
			{
				mult = mult + temp1->data; // add temp1 data upto temp2 data times
			}
			carry = mult / 10; //for carry first digit
			mult = mult % 10; // adding list to last digit
			if(count == 0)
			{
				add_result(&result_head1,&result_tail1,mult);
			}
			else
			{
				add_result(&result_head2,&result_tail2,mult);
			}

			temp1 = temp1->prev;
		}
		if(carry > 0 && count > 0) // it works after 1st digit
		{
			add_result(&result_head2,&result_tail2,carry);
		}
		if(count==0) // for leftover carry after exting from loop for one digit
		{
			if(carry > 0)
			{
				add_result(&result_head1,&result_tail1,carry);
			}
			add_result(&result_head1,&result_tail1,0); // adding dummy zero
		}
		if(count >= 1)
		{
			for(int i = 1;i<=count;i++) // adding zero for list 
			{
				insert_last(&result_head2,&result_tail2); // adding zero to head2 list
			}
			if(count%2 == 1)
			{
				//odd block
				do_addition(result_head1,result_tail1,result_head2,result_tail2,headR,tailR);
				free_node(&result_head2,&result_tail2);
				free_node(&result_head1,&result_tail1);
				add_result(headR,tailR,0); // Add dummy zero to result
			}
			else
			{
				//even block
				do_addition(*headR,*tailR,result_head2,result_tail2,&result_head1,&result_tail1);
				free_node(headR,tailR);
				free_node(&result_head2,&result_tail2);
				add_result(&result_head1,&result_tail1,0);
			}
		}
		temp2 = temp2->prev;
		count++;
	}
	if(count%2)
	{
		//odd count
		free_first(&result_head1);
		if(negative_flag)
			add_result(&result_head1,&result_tail1,'-');
		print_result(&result_head1,&result_tail1);
	}
	else
	{
		//even count
		free_first(headR);
		if(negative_flag)
			add_result(headR,tailR,'-');
		print_result(headR,tailR);
	}
	free_node(&result_head1,&result_tail1);
	free_node(&result_head2,&result_tail2);
	return success;
}
void insert_last(Dlist** head,Dlist** tail)
{
	Dlist* new = malloc(sizeof(Dlist));
	if(new == NULL)
	{
		printf("Memory allocation failed\n");
	}
	else
	{
		new->data = 0;
		new->prev = *tail;
		(*tail)->next = new;
		new->next = NULL;
		*tail = new;
	}
}
void free_first(Dlist** head)
{
	Dlist* temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

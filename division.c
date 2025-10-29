/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "header_file.h"
Status do_division(Dlist* head1,Dlist* tail1,Dlist* head2,Dlist* tail2,Dlist** headR,Dlist** tailR)
{
	int stop_flag=0;
	int count = 0,flag,result = 0;
	Dlist* temp;

	// if (head2 == NULL || (head2->next == NULL && head2->data == 0))
    // {
    //     printf("Error: Division by zero is not possible!\n");
    //     return failure;  // You can define FAILURE = 0 in your enum
    // }
	while(1)
	{
		flag = 0;
		if(result % 2 == 0)
		{
			count++;
			do_subt(head1,tail1,head2,tail2,headR,tailR);
			temp = *headR;
		}
		else
		{
			count++;
			do_subt(*headR,*tailR,head2,tail2,&head1,&tail1);
			temp = head1;
		}
		stop_flag = check_node(&temp,&head2);
		if(stop_flag == 1)
		{
			
			break;
		}
		else
		{
			if(result % 2 == 0)
				free_node(&head1,&tail1);
			else
				free_node(headR,tailR);

			result++;
		}
	}
	free_node(headR,tailR); // contain last reminder which is used for finding modulos also
	add_result(headR,tailR,count);
	//printf("Result is %d\n",count);
}
int check_node(Dlist** head1,Dlist** head2)
{
	Dlist* temp1 = *head1;
	Dlist* temp2 = *head2;
	while(temp1)
	{
		 if(temp1->data > temp2->data)
			return 0;
		else if(temp1->data < temp2->data)
			return 1;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return 0;
}

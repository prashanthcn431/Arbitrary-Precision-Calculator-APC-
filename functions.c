#include "header_file.h"


Status is_valid_number(char *num)
{
	int i=0;
	if (num[0] == '+' || num[0] == '-')
        i = 1;
	if (num[i] == '\0')
        return failure;
    for (; num[i] != '\0'; i++)
    {
         if (num[i] < '0' || num[i] > '9')
            return failure; 
    }
    return success;
}

Status validate_input(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <operand1> <operator> <operand2>\n", argv[0]);
        return failure;
    }

    

    if (!is_valid_number(argv[1]))
    {
        printf("Error: Invalid number '%s'. Must contain only digits.\n", argv[1]);
        return failure;
    }
    if (strcmp(argv[2], "+") != 0 &&
        strcmp(argv[2], "-") != 0 &&
        strcmp(argv[2], "x") != 0 &&
        strcmp(argv[2], "X") != 0 &&
        strcmp(argv[2], "/") != 0)
    {
        printf("Error: Only '+', '-', 'x'/'X', '/' operators are allowed.\n");
        return failure;
    }

    if (!is_valid_number(argv[3]))
    {
        printf("Error: Invalid number '%s'. Must contain only digits.\n", argv[3]);
        return failure;
    }

    printf("Valid input: %s %s %s\n", argv[1], argv[2], argv[3]);
    return 1; // success
}


Status insert_arguments(Dlist **head1,Dlist** tail1,Dlist** head2,Dlist** tail2,char* argv1,char* argv2)
{
	if (insert_at_last(head1, tail1, argv1) != success)
        return failure;
    if (insert_at_last(head2, tail2, argv2) != success)
        return failure;

    return success;

}


Status insert_at_last(Dlist** head,Dlist** tail,char* argv)
{
	for(int i=0;i<strlen(argv);i++)
	{
		if (argv[i] == '+' || argv[i] == '-')
        {    
			continue;
		}
		Dlist* new = malloc(sizeof(Dlist));
		if(new == NULL)
		{
			printf("Memory allocation failed\n");
			return failure;
		}
		
			new->data = argv[i] - 48;
				new->prev = NULL;
				new->next = NULL;
				if(*head == NULL)
				{
					*head = new;
					*tail = new;
				}
				else
				{
					new->prev = *tail;
					(*tail)->next = new;
					*tail = new;
				}
			
			
		
	}
	return success;
}

Status free_all(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** head3,Dlist** tail3)
{
	free_node(head1,tail1);
	free_node(head2,tail2);
	free_node(head3,tail3);
}

void free_node(Dlist** head,Dlist** tail)
{
	Dlist* temp = (*head);
	Dlist* back_up = NULL;
	while(temp != NULL)
	{
		back_up = temp->next;
		free(temp);
		temp = back_up;
	}
	*head = NULL;
	*tail = NULL;
}

int find_bigger(Dlist** head1,Dlist** head2)
{
	Dlist* temp = *head1;
	Dlist* temp2 = *head2;
	while(temp && temp2)
	{
		if(temp->data > temp2->data)
			return 1;
		else if(temp2->data > temp->data)
			return 3;
		temp = temp->next;
		temp2 = temp2->next;

	}
	return 0;
}

void print_result(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;
    int leading_zero = 1;   // flag to skip leading zeros
    int has_digits = 0;     // check if we printed any digit

    printf("Result = ");

    while (temp != NULL)
    {
        if (temp->data == '-') // handle negative sign
        {
            printf("-");
        }
        else if (temp->data != 0 || !leading_zero) // skip leading zeros
        {
            printf("%d", temp->data);
            leading_zero = 0;
            has_digits = 1;
        }

        temp = temp->next;
    }
    if (!has_digits)
        printf("0");

    printf("\n");
}

int find_length(char* argv)
{
	int i = 0,count = 0;
	while(argv[i] != '\0')
	{
		if(argv[i] == '-' || argv[i] == '+')
		{
			i++;
			continue;
		}
		else
		{
			count++;
			i++;
		}
	}
	return count;
}


int is_zero(Dlist *head)
{
    while(head)
    {
        if(head->data != 0)
            return 0;
        head = head->next;
    }
    return 1;
}
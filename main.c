/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/

#include"header_file.h"
int negative_flag=0;	
int main( int argc, char * argv[])
{
	/*Error handling to pass the valid arguments*/
	if(argc < 4)
	{
		printf("Please Pass Valid Arguments....\n");
		printf("Usage : ./a.out <operand - 1>  <operator> <operand - 2>\n");
		return 0;
	}

	if (!validate_input(argc, argv))
        return failure;
	/*Validation for the operator*/
	if((strcmp(argv[2],"+") !=0) && (strcmp(argv[2],"-") !=0) && (strcmp(argv[2],"x") !=0) &&  (strcmp(argv[2],"X") !=0) && (strcmp(argv[2], "/") !=0))
	{
		printf("Please pass valid Operator\n");
		return 0;
	}

	/*Declare pointers for the data and result*/
	Dlist *head1 = NULL;
	Dlist *tail1 = NULL;
    Dlist *head2 = NULL;
	Dlist *tail2 = NULL;
    Dlist *headR = NULL;
	Dlist *tailR = NULL;

	              
	/*Insert arguments into lists*/      
	if( insert_arguments(&head1,&tail1,&head2,&tail2,argv[1],argv[3]) != success)
	{
		printf("Inserting failed\n");
		return failure;
	}
	

    char ch = argv[2][0];       //argv[2]   = "-"     // string
	int difference;              //argv[2][0] = '-'     // single character
	if((ch != 'x')|| (ch != 'X'))
	{
		/*Find length of the both arguments excluding sign*/
		int length1 = find_length(argv[1]);
		int length2 = find_length(argv[3]);

		/*Based on difference add 0's to make lists equal*/
		if(length1 > length2)
		{
			difference = length1 - length2;
			for(int i = 0;i< difference;i++)
			{
				add_result(&head2,&tail2,0);			//run loop to add zeroes
			}
		}
		else if(length2 > length1)
		{
			difference = length2 - length1;
			for(int i = 0;i<difference;i++)
			{
				add_result(&head1,&tail1,0);
			}
		}
	}

	/*Find big number among two lists*/
	int big_num = find_bigger(&head1,&head2);
	if( ch == '+')											//if operator is +
	{
		if( argv[1][0] == '-' && argv[3][0] == '-')			//if both signs are negative add  sign bit
		{
			negative_flag = 1;
		}
		else if(argv[big_num][0] == '-')				//if big num has - add negative sign
		{
			negative_flag = 1;
		}
	}
	else if( ch == '-')					//if ch is -
	{
		if(big_num == 1 && argv[1][0] == '-') 		//if both arguments are - enable negative flag 
		{
			negative_flag = 1;
		}
		else if(argv[3][0] != '-' && big_num != 1)		//if second argument has - and big number is not 1 enable negative flag
		{
			negative_flag = 1;
		}
	}
	else if( ch == '/' || ch == 'x' || ch == 'X')
	{
		if( argv[1][0] == '-' && argv[3][0] != '-')
			negative_flag = 1;
		else if( argv[1][0] != '-' && argv[3][0] == '-')
			negative_flag = 1;
	}

	/*Choose correct operator based on signs given for arguments*/
	if( argv[2][0] == '+')
	{
		if ( (argv[1][0] != '-' && argv[3][0] == '-') || (argv[1][0] == '-' && argv[3][0] != '-'))
		{
			ch = '-';
		}
		else
		{
			ch = '+';
		}
	}
	else if( argv[2][0] == '-')
	{
		if( (argv[1][0] == '-' && argv[3][0] != '-') || (argv[1][0] != '-' && argv[3][0] == '-'))
		{
			ch = '+';
		}
		else
		{
			ch = '-';
		}
	}


	switch(ch)
	{
		case '+':
		/*Call addition Function*/
			if( do_addition(head1,tail1,head2,tail2,&headR,&tailR) == success)
			{
				printf("Addition successfully done.....\n");
			}
			else
			{
				printf("Addition failed....\n");
			}
			break;

		case '-':
		/*Call Subtraction Function*/
			if(big_num == 1)
			{
				if (do_subt(head1,tail1,head2,tail2,&headR,&tailR) == success)
				{
                   printf("Subtraction successfully done.....\n");
				}
                else
				{
                 	printf("Subtraction failed\n");
				}
			}
			else if( big_num == 3)
			{
				if(do_subt(head2,tail2,head1,tail1,&headR,&tailR) == success)
				{
					printf("Subtraction successfully done....\n");
				}
				else
				{
					printf("Subtraction failed\n");
				}
			}
			else
			{
				printf("Result is 0\n");
				return 0;
			}
			break;

		
		case 'x':
		case 'X':
		/*Call Multilication Function*/
			if(do_mul(head1,tail1,head2,tail2,&headR,&tailR) == success)
			{
				printf("Multiplication successfully done......\n");
			}
			else
			{
				printf("Multiplication failed\n");
			}
			break;

		case '/':
		/*Call division Function*/
			if(big_num == 3)
			{
				printf("Result is 0\n");		//if denominator is big number than numerator the result is 0
				return 0;
			}
			else
			{
				if (is_zero(head2))
				{
					printf("Error: Division by zero is not allowed!\n");
					return 0;   // stop program
				}

				if(do_division(head1,tail1,head2,tail2,&headR,&tailR) == success)
				{
					printf("Division successfully done......\n");
				}
			}

			break;
	}

	/*Based on negative flag add sign for result*/
	if(negative_flag == 1)
	{
		add_result(&headR,&tailR,'-');
	}
	if(ch != 'x' && ch != 'X')
	{
		print_result(&headR,&tailR);
	}
	/*Free all the nodes after the operation*/
	free_all(&head1,&tail1,&head2,&tail2,&headR,&tailR);
	return 0;

 


}

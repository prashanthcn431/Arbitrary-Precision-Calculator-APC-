#ifndef HEADER_FILE
#define HEADER_FILE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct node
{
	struct node* prev;
	int data;
	struct node* next;
}Dlist;

typedef enum 
{
	failure,
	success,
}Status;


Status insert_arguments( Dlist**head1,Dlist** tail1,Dlist** head2,Dlist** tail2,char* argv1,char* argv2);

Status insert_at_last(Dlist** head1,Dlist** tail1,char* data);

Status do_addition(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);

Status add_result(Dlist **head3,Dlist **tail3,int sum);

Status free_all(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** head3,Dlist** tail3);

void free_node(Dlist** head,Dlist** tail);

int find_bigger(Dlist** head1,Dlist** head2);

Status do_subt(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);

void print_result(Dlist** head,Dlist** tail);

int find_length(char* argv);

Status do_division(Dlist* head1,Dlist* tail1,Dlist* head2,Dlist* tail2,Dlist** head3,Dlist** tail3);

int check_node(Dlist** head1,Dlist** head2);

Status do_mul(Dlist* head1,Dlist* tail1,Dlist* head2,Dlist* tail2,Dlist** head3,Dlist** tail3);

void insert_last(Dlist** head,Dlist** tail);

void insert_first(Dlist** head, Dlist** tail, int data);

void free_first(Dlist** head);

int is_zero(Dlist *head);

Status do_modulus(Dlist* head1, Dlist* tail1, Dlist* head2, Dlist* tail2, Dlist** headRem, Dlist** tailRem);

Status is_valid_number(char *num);

Status validate_input(int argc, char *argv[]);
#endif
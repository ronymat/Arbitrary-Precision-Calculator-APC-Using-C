#ifndef APC_H
#define APC_H
//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//macros used for return 
#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY 2
//Structure definition for doubly linked list node
typedef struct list
{
 int data;
 struct list *prev;
 struct list *next;
}Dlist;

//list of functions used in the program
int arg_validation(int argc,char* argv[]);
int str_to_list(char *str, Dlist **head, Dlist **tail);
int  insert_first(Dlist **head, Dlist **tail,int data);
int insert_last(Dlist **head,Dlist **tail,int data);
void remove_leading_zeros(Dlist **head, Dlist **tail);
int addition(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res);
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res);
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res);
int division(Dlist *head1,Dlist *head2,Dlist *tail1, Dlist *tail2, Dlist **head_res,Dlist **tail_res);
int compare_lists(Dlist *head1, Dlist *head2);
int print_list(Dlist *head);

#endif
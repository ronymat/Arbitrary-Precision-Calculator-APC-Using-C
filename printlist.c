#include "apc.h"

int print_list(Dlist *head)
{
    if(head==NULL)//check weather the list is empty
    {
         printf("List is empty\n");
        return LIST_EMPTY;
    }
    while(head!=NULL)//move till last end of node
    {
        printf("%d", head->data);
        head = head->next;
    }
    return SUCCESS;
}
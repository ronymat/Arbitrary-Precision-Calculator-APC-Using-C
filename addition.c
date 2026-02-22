#include "apc.h"

int addition(Dlist *tail1,Dlist *tail2,Dlist **head_res,Dlist **tail_res)
{
 int carry=0;

  // Loop until both lists are completely processed
  while(tail1!=NULL || tail2!=NULL)
  {
    int sum=carry;
    if(tail1!=NULL)
    {
        sum=sum+tail1->data;
        tail1=tail1->prev;// move to previous digit
    }
    if(tail2!=NULL)
    {
        sum=sum+tail2->data;
        tail2=tail2->prev;// move to previous digit
    }
    // Extract digit and carry from sum 
    int digit=sum%10;
    carry=sum/10;

    Dlist *new=malloc(sizeof(Dlist));  // Create new node for result digit
    if(new==NULL)
    {
        printf("Error: FAiled to allocate node!!");
        return FAILURE;
    }
     
     new->data=digit;
     new->prev=NULL;
     new->next=*head_res;
      // If result list is not empty, update previous pointer 
     if(*head_res!=NULL)
     {
        (*head_res)->prev=new;
     }
     else//it is when no nodes are present
     {
        // First node in result list, so tail also points to this node
        *tail_res = new;
     }
     *head_res=new;
  }

   // If carry remains after loop, add it as a new node at front
  if(carry)
  {
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL) 
    {
     printf("Error: Memory allocation failed in addition\n");
     return FAILURE;
    }
    new->data=carry;
    new->prev=NULL;
    new->next=*head_res;
    // If result list is not empty, update previous pointer 
     if(*head_res!=NULL)
     {
        (*head_res)->prev=new;
     }
     else//it is when no nodes are present
     {
     // First node in result list, so tail also points to this node
     *tail_res = new;
     }
     *head_res=new;
  }
  remove_leading_zeros(head_res, tail_res);
  head_res = NULL;
  tail_res = NULL;
  return SUCCESS;
}
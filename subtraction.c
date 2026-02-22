#include "apc.h"

int subtraction(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res)
{
    int borrow=0;

   // Continue until both lists are completely processed 
    while(tail1!=NULL || tail2!=NULL)
    {
      int num1=0,num2=0;
      if(tail1!=NULL)// Get digit from first list if available
      {
        num1=tail1->data;
        tail1=tail1->prev;
      }

      if (tail2!=NULL)// Get digit from second list if available
      {
        num2=tail2->data;
        tail2=tail2->prev;
      }

      num1=num1-borrow;// Subtract previous borrow from num1

      if(num1<num2) // Apply borrow logic if needed
      {
        num1=num1+10;
        borrow=1;
      }
      else
      {
      borrow=0;
      }
      int diff=num1-num2;
      // Allocate memory for new result node
      Dlist *new=malloc(sizeof(Dlist));
      if(new==NULL)
      {
        printf("Error: Memory allocation failed !!!");
        return FAILURE;
      }
       // Store the result digit in the node
      new->data=diff;
      new->prev=NULL;
      new->next=*head_res;
      
      // Update previous pointer of existing head node
     if(*head_res!=NULL)
     {
        (*head_res)->prev=new;
     }
     else
     {
         *tail_res=new;
     }
        *head_res=new;
    }
     remove_leading_zeros(head_res, tail_res);
    head_res = NULL;
    tail_res = NULL;
    return SUCCESS;
}
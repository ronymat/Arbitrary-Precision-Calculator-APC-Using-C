#include "apc.h"

int multiplication(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res)
{
    //used to give zero to the list first since list is empty
  Dlist *res_head=NULL;
  Dlist *res_tail=NULL;
  insert_first(&res_head,&res_tail,0);

  int Shiftcount=0;// to get count of number of shifts needed

  while ((tail2!=NULL))
  {
    Dlist *temp_head=NULL;
    Dlist *temp_tail=NULL;
    Dlist *t1=tail1;
    int carry=0;
    //loop to run the first term for multiplication
    //Multiply each digit of first number with current second number
    while(t1!=NULL)
    {
    int prod;
    prod =t1->data * tail2->data + carry;
    insert_first(&temp_head,&temp_tail,prod%10);//to store only one digit 
    carry=prod/10;//carry is stored 
    t1=t1->prev;//move to previous digit
    }
    //if carry is present last
    if(carry)
    {
        insert_first(&temp_head,&temp_tail,carry);
    }
    //loop to add zeros at the end according to size of number 
    for(int i=0;i<Shiftcount;i++)
    {
        insert_last(&temp_head,&temp_tail,0);
    }
    //used to store the result data after addition
    Dlist *new_head=NULL;
    Dlist *new_tail=NULL;
    addition(res_tail,temp_tail,&new_head,&new_tail);

    res_head=new_head;
    res_tail=new_tail;

    Shiftcount++;
    tail2=tail2->prev;
  }
   //final result is given
  *head_res=res_head;
  *tail_res=res_tail;

  return SUCCESS;
}
 
#include "apc.h"
#include<ctype.h>

int check_operator(char ch)//checks the operator is presrnt or not
{
  char operators[]="+-*/";
  for(int i=0; operators[i]!='\0'; i++)
  {
      if(operators[i] == ch)
      {
        return SUCCESS;
      }
  }
  return FAILURE;
}
// check weather the number is correct
int check_number(char *str)
{
    int i=0;
    //checks weather operand sighn is correct
    if(str[i]=='+' || str[i]=='-')
    {
        i++;
        if(str[i]=='+' || str[i]=='-')//when multiple sighns came return failure
        {
            printf("Error: Multiple sighns are given for operand\n");
            return FAILURE;
        }
    }
    if(str[i]=='\0')//check weather one number is there or not
    {
     return FAILURE;
    }

    //check rest are only numbers 
    while(str[i]!='\0')
    {
        if(!isdigit(str[i]))
        {
        printf("Error: Only digits should be present\n");
         return FAILURE;
        }
        i++;
    }
    return SUCCESS;
}

int arg_validation(int argc, char* argv[])
{
    if(argc!=4)//check all arguments are there
    {
        printf("Error: Wrong arguments are passed \n use: %s operand1 operator operand 2\n",argv[0]);
        return FAILURE;
    }

    //check only digits are there in the arguments 1 and 2

    if(check_number(argv[1])==FAILURE)
    {
        printf("Error: Invalid operand is passed in second argument\n");
        return FAILURE;
    }
    if(check_number(argv[3])==FAILURE)
    {
        printf("Error: Invalid operand is passed in third argument\n");
        return FAILURE;
    }
    
    //check operator is there in argument 2
    if(check_operator(argv[2][0])==FAILURE)
    {
     printf("Error: Invalid operator is passed\n");
     return FAILURE;
    }
return SUCCESS;
}
//find list length
int list_length(Dlist *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
//compare list size
int compare_lists(Dlist *head1, Dlist *head2)
{
    int len1 = list_length(head1);
    int len2 = list_length(head2);
    //first check with length
    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;
    //if  same length ,compare digit by digit
    while (head1 && head2)
    {
        if (head1->data > head2->data)
        {
            return 1;
        }
        if (head1->data < head2->data)
         {
             return -1;
         }

        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}

//convert str to list

int str_to_list(char *str, Dlist **head, Dlist **tail)
{
    int i=0;

    if(str[i]=='+' || str[i]=='-')
    {
        i++;
    }
    //atleast one digit is required for operation
      if (str[i] == '\0')
    {
        printf("Error: No digits in number\n");
        return FAILURE;
    }
    
    while(str[i]!='\0')
    {
      if(!isdigit(str[i]))//check weather character is a number or not
      {
            printf("Error: Invalid number is given !\n");
            return FAILURE;
      }
     
      Dlist *new=malloc(sizeof(Dlist));//allocate memory
      if(new==NULL)
      {
        printf("Error: Memory allocation failed !");
        return FAILURE;
      }

      new->data=str[i]-'0';//or use -48 to convert string to integer
      new->prev=NULL;
      new->next=NULL;

      if(*head==NULL)
      {
        *head=*tail=new;
      }
      else
      {
        new->prev=*tail;
        (*tail)->next=new;
        *tail=new;
      }
      i++;
    }
    return SUCCESS;
}
// to remove unwanted zeros 
void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && (*head)->next != NULL)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
    // fix tail if list became single node
    if (*head == NULL)
        *tail = NULL;
    else
    {
        Dlist *t = *head;
        while (t->next)
            t = t->next;
        *tail = t;
    }
}

// Insert a node at the beginning of the doubly linked list
int  insert_first(Dlist **head, Dlist **tail,int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        return FAILURE;
    }
    
    new->data=data;
    new->prev=NULL;
    new->next=*head;

    if(*head!=NULL)    // If list is not empty, update old head's prev pointer
    {
    (*head)->prev=new;
    }
    else
    {
        *tail=new;  // If list was empty, new node is also the tail
    }
    *head=new;
}

// Insert a node at the end of the doubly linked list 
int insert_last(Dlist **head,Dlist **tail,int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        return FAILURE;
    }

    new->data=data;
    new->prev=*tail;
    new->next=NULL;

    if(*tail!=NULL) // If list is not empty, link old tail to new node
    {
        (*tail)->next=new;
    }
    else
    {
        *head=new;   // If list was empty, new node is also the head
    }
    *tail=new;
}


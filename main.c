#include "apc.h"

int main(int argc,char *argv[])
{
  printf("================================================\n");
  printf("          ARBITARY PRECISION CALCULATOR       ");
  printf("\n================================================\n");
    //argument validation
  if(arg_validation(argc,argv)==FAILURE)
  {
    printf("Error: in validation!!!\n");
    printf("\n================================================\n");
    return FAILURE;
  }
  else
  {
  //printf("Argument validation is successful...\n");
  }
//variable decleration for 3 lists

//for operator 1 head and tail is assighn NULL
Dlist *head1=NULL;
Dlist *tail1=NULL;
//for operator 2 head and tail is assighn NULL
Dlist *head2=NULL;
Dlist *tail2=NULL;
//for result operator  head and tail is assighn NULL
Dlist *head_res=NULL;
Dlist *tail_res=NULL;

//convert str to list for both numbers
if(str_to_list(argv[1],&head1,&tail1)==FAILURE)
{
  printf("Error: in convertion !!!\n");
  printf("\n================================================\n");
  return FAILURE;
}
else
{
//  printf("Argument convertion of first is successful...\n");
}

if(str_to_list(argv[3],&head2,&tail2)==FAILURE)
 {
     printf("Error: in convertion !!!\n");
     printf("\n================================================\n");
    return FAILURE;
  }
  else
  {
  //printf("Argument convertion of Second is successful...\n");
  }
  char *op1 = argv[1];
  char *op2 = argv[3];
 

    printf("Operand 1 : %s\n\n", op1);
    printf("Operand 2 : %s\n\n", op2);

//select operation to perform
char operator=argv[2][0];
switch(operator)
{
    case '+':
    {
      printf("Operation : Addition\n\n");
      int negative=0;
      char sign1=argv[1][0];
      char sign2=argv[3][0];

      //if both are positive
      if(sign1!='-' && sign2!='-')
      {
        addition( tail1,tail2,&head_res,&tail_res);
      }
      //if first is positive and second is negative
      else if (sign1!='-' && sign2=='-')
      {
        int cmp = compare_lists(head1, head2);//it is used to check which one is bigger number
          if(cmp<0)//if first less than second
          {
           subtraction(tail2, tail1, &head_res, &tail_res);
           negative = 1;
          }
          else
          {
              subtraction(tail1, tail2, &head_res, &tail_res);
          }
       }
      
      //if first is negative and second is positive
      else if (sign1=='-' && sign2!='-')
      {
        int cmp = compare_lists(head2, head1);//it is used to check which one is bigger number
          if(cmp<0)//if second less than first
          {
            subtraction(tail1, tail2, &head_res, &tail_res); 
            negative = 1;
          }
          else
          {
            subtraction(tail2, tail1, &head_res, &tail_res); 
          }
      }
      else if (sign1=='-' && sign2=='-')
      {
        addition( tail1,tail2,&head_res,&tail_res);
        negative=1;
      }
         //print result
         printf("\n================================================\n");
          printf("Result = ");
          if (negative)
          printf("-");
          print_list(head_res);
          printf("\n\nAddition Successfull !!!");
          break;
    }
    case '-':
    {
       printf("Operation : Subtraction\n\n");
        int negative=0;
        char sign1 = argv[1][0];
        char sign2 = argv[3][0];

        // if first is + and second is +
         if (sign1 !='-' && sign2 != '-')
        {  
          int cmp = compare_lists(head1, head2);//it is used to check which one is bigger number
              if (cmp < 0)   // first number < second number result negative
          {
              negative = 1;
              subtraction(tail2, tail1, &head_res, &tail_res); 
          }
          else        
          {
              subtraction(tail1, tail2, &head_res, &tail_res); 
          }
         }  
        //if first number + and second is -
        else if (sign1 != '-' && sign2 == '-')
        {
           addition(tail1, tail2, &head_res, &tail_res);
        }
        //if first number is - and second is +
        else if (sign1 == '-' && sign2 != '-')
        {
           addition(tail1, tail2, &head_res, &tail_res);
           negative=1;
        }
        //if first is + and second is -
       else if (sign1 == '-' && sign2 == '-')
        {
            int cmp = compare_lists(head2, head1);
             if (cmp < 0)   // second number < first number result negative
            {
              subtraction(tail1, tail2, &head_res, &tail_res); 
               negative = 1;
            }
            else
            {
                subtraction(tail2, tail1, &head_res, &tail_res); 
            }
        }
        //print result
          printf("================================================\n");
          printf("Result = ");
          if (negative)
          printf("-");
          print_list(head_res);
          printf("\n\nSubtraction Successfull !!!");
          break;
    }
    case '*':
    {
       printf("Operation : Multiplication\n");
        int negative=0;
        char sign1 = argv[1][0];
        char sign2 = argv[3][0];
        //if both nos are positive
        if(sign1!='-' && sign2!='-')
        {
          multiplication(tail1,tail2,&head_res,&tail_res);
        }
        //if both are negative
        else if (sign1=='-' && sign2=='-')
        {
           multiplication(tail1,tail2,&head_res,&tail_res);
        }
        else 
        {
          multiplication(tail1,tail2,&head_res,&tail_res);
          negative=1;
        }
        //print result
        printf("================================================\n");
        printf("Result = ");
        if(negative)
        printf("-");
        print_list(head_res);
        printf("\n\nMultiplication Successful !!!");
        break;
    }
    case '/':
    {
        printf("Operation : Division\n");
        int negative=0;
        char sign1 = argv[1][0];
        char sign2 = argv[3][0];
        //perform division operation
       if(division(head1,head2,tail1,tail2,&head_res,&tail_res)==FAILURE)
       {
         printf("================================================\n");
        return FAILURE;
       }
       //if any one of the operation is negative        
       if((sign1=='-' && sign2!='-')||(sign1!='-' && sign2=='-'))
       {
        negative=1;
       }  
       //print result
        printf("================================================\n");
          printf("Result = ");
        if(negative)
        printf("-");
        print_list(head_res);
        printf("\n\nDivision Successful !!!");
        break;  
    }
}
     printf("\n================================================\n");
return SUCCESS;
}


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node               //Structure of a node in polynomial which contains coefficient and power and address of next node
{
   int coeff;
   int pow;
   struct Node* next;
};

void Show( struct Node *Head)    //To print the nodes
{
  while(Head != NULL)
  {
      if(Head->pow == 0)
     {
      printf("%d", Head->coeff);
     }else {
       if(Head->coeff!=0){
         printf("%dx^%d", Head->coeff , Head->pow);
       }
     }
     Head = Head->next;
      if(Head != NULL && Head->coeff>0){
        printf(" +");
      }else
      {
        printf(" ");
      }
  }
  printf("\n");
}

void Create_poly(int coeff,int pow,struct Node** Head)       //To construct the polynomial
{
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->coeff=coeff;
    NewNode->pow=pow;
    NewNode->next=NULL;
    struct Node* N = *Head;
    if(*Head == NULL)
    {
        *Head=NewNode;
    }else{

    while(N->next != NULL)
    {
        N=N->next;
    }
    N->next = NewNode;
    }

}
void Addpoly(struct Node* n1,struct Node* n2,struct Node** n3)         // To add two polynomials

{
    while(n1!=NULL || n2!=NULL)
    {
        if(n1==NULL)
    {
        Create_poly(n2->coeff,n2->pow,n3);
        n2=n2->next;
    }
    else if(n2==NULL)
    {
        Create_poly(n1->coeff,n1->pow,n3);
        n1=n1->next;
    }
    else if(n2->pow > n1->pow)
      {
        Create_poly(n2->coeff,n2->pow,n3);

        n2=n2->next;

      }
      else if(n1->pow > n2->pow)
      {
        Create_poly(n1->coeff,n1->pow,n3);

        n1=n1->next;

      }
    else if(n1->pow == n2->pow)
      {
        Create_poly(n1->coeff+n2->coeff,n1->pow,n3);
        n1=n1->next;
        n2=n2->next;

      }
    }
}

void Subtractpoly(struct Node* n1,struct Node* n2,struct Node** n4)     // To subtract two polynomials

{
    while(n1!=NULL || n2!=NULL)
    {
        if(n1==NULL)
    {
        Create_poly(- n2->coeff,n2->pow,n4);
        n2=n2->next;
    }
    else if(n2==NULL)
    {
        Create_poly(n1->coeff,n1->pow,n4);
        n1=n1->next;
    }
    else if(n2->pow > n1->pow)
      {
        Create_poly(-n2->coeff,n2->pow,n4);

        n2=n2->next;

      }
      else if(n1->pow > n2->pow)
      {
        Create_poly(n1->coeff,n1->pow,n4);

        n1=n1->next;

      }
    else if(n1->pow == n2->pow)
      {
        Create_poly(n1->coeff-n2->coeff,n1->pow,n4);
        n1=n1->next;
        n2=n2->next;

      }
    }
}

int Evaluate_value(int value,struct Node* Head)                     //To evaluate the polynomial by putting value in it
{
   int k=0;
   while(Head!=NULL)
   {
     int s=(Head->coeff)*(pow(value,Head->pow));
     k+=s;
     Head = Head->next;
   }
   printf("%d",k);
   printf("\n");
}


void Free_list(struct Node* Head)          //In order to free the memory space after each test case
{
   struct Node* temp;

   while (Head != NULL)
    {
       temp = Head;
       Head = Head->next;
       free(temp);
    }

}
int main()                          //Main Function
{
    int K;
    scanf("%d",&K);
    while(K--)
    {
        struct Node* n1=NULL;
        struct Node* n2=NULL;
        struct Node* n3=NULL;
        struct Node* n4=NULL;
        int a,b;
        scanf("%d",&a);
        int Powa=a;
        for(int i=0;i<=a;i++)
        {
            int coeff;
            scanf("%d",&coeff);
            if(coeff!=0)
            {
                Create_poly(coeff,Powa,&n1);
            }
             Powa--;
        }
        scanf("%d",&b);
        int Powb=b;
        for(int i=0;i<=b;i++)
        {
            int coeff;
            scanf("%d",&coeff);
            if(coeff!=0)
            {
                Create_poly(coeff,Powb,&n2);
            }
             Powb--;
        }
        int value;scanf("%d",&value);            //Taking value from user
        printf("P1(x) :");Show(n1);               //Printing n1
        printf("P2(x) :");Show(n2);               //Printing n2
        Addpoly(n1,n2,&n3);
        printf("P3(x) = P1(x) + P2(x) : ");Show(n3);     //Printing n1+n2
        Subtractpoly(n1,n2,&n4);
        printf("P4(x) = P1(x) - P2(x) : ");Show(n4);     //Printing n1-n2
        printf("P1(%d): ",value);Evaluate_value(value,n1);                //Evaluating n1
        printf("P2(%d): ",value);Evaluate_value(value,n2);                //Evaluating n2
        printf("P3(%d): ",value);Evaluate_value(value,n3);                //Evaluating n3
        printf("P4(%d): ",value);Evaluate_value(value,n4);                //Evaluating n4
        Free_list(n1);                                                    //To free the space

    }
return 0;
}

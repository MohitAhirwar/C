//Linked list operations

#include<stdio.h>
#include<stdlib.h>

struct Node              //structure of linked list
{
 int data;
 struct Node *next;

};

struct Node* Head;     //head pointer

void Insertion_beg(int Value)  //Insert value at beginning
{
struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
NewNode->data = Value;
NewNode->next = Head;
Head = NewNode;
}
void Insertion_end(int Value,int Pos)  //Insert value at end by Pos
{
struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
NewNode->data = Value;
NewNode->next = NULL;
Pos++;
if(Pos == 1)
{
NewNode->next=Head;
Head = NewNode;
}
else
{
struct Node* N = Head;
Pos--;

  NewNode->next = N->next;
  N->next = NewNode;
}
}
void Insersion_at_the_end(int Value)
{
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* N = Head;
    NewNode->data = Value;
    NewNode->data = NULL;
    while(N->next != NULL)
    {
        N = N->next;
    }
    N->next=NewNode;
}

void DeleteUsingPos(int Pos)  // Taking position as a parameter for node has to be deleted
{

struct Node* Cur=Head;
struct Node* Pre=Head;

if (Head = NULL) // Checking if the Linked list is empty then we cannot delete
{
    printf("Cannot Delete");
}
else if(Pos==1)  // When position is 1
      {

       Head = Cur->next;
        free(Cur);
        Cur=NULL; }


else{
    while(Pos!=1) // When position is not 1
    {
        Pre=Cur;
        Cur=Cur->next;
        Pos--;
    }
    Pre->next=Cur->next;
    free(Cur);
    Cur=NULL;

}
}
void Finding_Node(int Value){
   struct Node* N=Head;
   struct Node* pre=Head;
   struct Node** point=&Head;
   int Pos=0;
   while (N!=NULL)
   {
      Pos++;
      pre=N;
      if(N->data==Value){
      printf("Value %d node is at position %d in the linked list.",Value,Pos);
      printf("\n");
      printf("Difference in its allocated memory to that of current head :%d",pre -*point); printf("\n");
      return;
     }
     N=N->next;
   }
   printf("Cannot find any such node in linked list\n");
}
int Finding_size()
{
   int size=0;
   struct Node* N=Head;
   while (N!=NULL)
   {
      size++;
      N=N->next;
   }
   return size;
}
void Display_Node(){
   struct Node* N=Head;
   while (N!=NULL)
   {
      printf("%d ",N->data);
      N=N->next;
   }
   printf("\n");
}
void DeleteUsingValue(int Value){
   struct Node* N=Head;
   int pos=0;
   while (N!=NULL)
   {

     pos++;
     if((N->data)==Value){
        DeleteUsingPos(pos);
        return;
     }
     N=N->next;
   }
   printf("Cannot delete\n");
}
int flag2=1;
int main(){
   Head==NULL;    //Empty List
   int flag1=1,choice,value,last,first=1;
   while(flag1){
       if(flag2){
        printf("Enter the choice:\n");
       }
       flag2=1;
      scanf("%d",&choice);
      if(choice==0){
         flag1=0;
      }else if(choice>0 && choice<=8){
         if(choice==1){
            printf("Enter the data value:\n");
            scanf("%d",&value);
            Insertion_beg(value);
         }else if(choice==2){
            printf("Enter the data value:\n");
            scanf("%d",&value);
            Insertion_end(value,Finding_size());
         }else if(choice==3){
            DeleteUsingValue(first);
         }else if(choice==4){
            DeleteUsingPos(Finding_size());
         }else if(choice==5){
            printf("Enter the data value:\n");
            scanf("%d",&value);
            DeleteUsingValue(value);
         }else if(choice==6){
            printf("Enter the data value:\n");
            scanf("%d",&value);
            Finding_Node(value);
         }else if(choice==7){
           int k=Finding_size();
           printf("%d",k);printf("\n");
         }else if(choice==8){
            Display_Node();
         }
      }else{
           printf("Wrong Input.\nEnter your choice again:\n");
           flag2=0;
      }
   }
}

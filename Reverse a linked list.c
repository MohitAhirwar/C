// Reverse a linked list

#include<stdio.h>
#include<stdlib.h>

struct Node              //structure of linked list
{
 int data;
 struct Node *next;
};

struct Node* start;     //head pointer


void Insertion_beg(int Value)  //Insert value at beginning
{
struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
NewNode->data = Value;
NewNode->next = start;
start = NewNode;

}


void createList(int n)
{
	int i,data;
	if(n==0)
		return start;

	printf("Enter elements in linked list : \n");
	scanf("%d",&data);
	Insertion_beg(data);

	for(int i=2; i<=n; i++)
    {

        scanf("%d", &data);
        Insertion_beg(data);
    }
Reverse_List();   // Since all elements are inserted at beg so the original linked list will be reversed of that...
}
void Display_List()
{   struct Node *p;
    if(start == NULL)
    {printf("List is empty.");
      return;
    }
    else
    {
    p = start;
    while(p!=NULL)
       {   if(p->next==NULL)
           {printf("%d ",p->data);}
           else
            printf("%d, ",p->data);

           p = p->next;
        }
    }
}

void Reverse_List()
{
    struct Node *prev;
    struct Node *curr;

    if(start != NULL)
    {   prev = start;
        curr = start->next;
        start = start->next;
        prev->next = NULL;
        while(start != NULL)
        {  start = start->next;
            curr->next = prev;
            prev = curr;
            curr = start;
        }
        start= prev;
    }
}

int main()
{
    int n;
    printf("Enter no. of elements in linked list:");
    scanf("%d", &n);            //To scan no. of elements in list
    createList(n);               //To create the list
    printf("\nData in the Linked list is:\n");
    Display_List();              // original list
    Reverse_List();              //To reverse the linked list
    printf("\nData in Reverse Linked list is:\n");
    Display_List();        // Reversed list
    return 0;
}

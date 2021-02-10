#include<stdio.h>
#include<stdlib.h>

struct stack    //Stack node
{
    int info;
    struct stack *next;
}*top;

void initializeStk()    //To initialize a stack
{
    top = NULL;
}

void push(int data)               //Push data into the stack
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    if(temp == NULL)
    {
        printf("Stack Overflow");
        return;
    }
    temp->info = data;
    temp->next = top;
    top = temp;
}

int isEmpty()          // Check if the stack is empty or not
{

    if(top == NULL)
        return 1;
    else
        return 0;
}

int pop()                //Pop data from top of the stack
{
  struct stack *temp;
  int data;
  if(isEmpty())
  {
      printf("\nstack underflow");
      exit(1);

  }
  temp = top;
  data = temp->info;
  top = top->next;
  free(temp);
  return data;
}

int Stacktop()          //Returning top of the stack
{
    if(isEmpty())
    {
        printf("\nStack underflow");
    }
    return top->info;
}


struct node                 //Structure of node of a Tree
{
    struct node *Left_child;
    int data;
    struct node *Right_child;
};

struct node *root;         //Global Pointer to tree i.e,"root"

struct node *getnode(int x)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->Left_child = NULL;
    p->Right_child = NULL;
    return p;
}

struct node *Insert_Node(struct node *p,int x)    //To insert node in BST
{
    if(p==NULL)
        p=getnode(x);
    else if(x < p->data)
        p->Left_child = Insert_Node(p->Left_child,x);
    else if(x>p->data)
        p->Right_child = Insert_Node(p->Right_child,x);
    else
        printf("\n %d is already present in tree!!\n",x);
    return p;
}

struct node *deleteNode_InorderSuccessor(struct node *root,int x)  // To delete node from BST
{
     struct node *par,*p,*ch,*s,*ps;
        p=root;
        par = NULL;
        while(p!=NULL)
        {
            if(x==p->data)
                break;
            par=p;
            if(x<p->data)
                p = p->Left_child;
            else
                p = p->Right_child;
        }
    if(p==NULL)
    {
        printf("%d not found \n",x);
        return root;
    }
   /*  CASE: 2 children */
    if(p->Left_child!=NULL && p->Right_child!=NULL) //Finding Inorder Successor and its parent
    {
        ps=p;
        s=p->Right_child;
        while(s->Left_child!=NULL)
        {
            ps=s;
            s=s->Left_child;
        }
        p->data=s->data;
        p=s;
        par=ps;
    }
     /*  CASE: 1 or no child */
    if(p->Left_child!=NULL)  // node to be deleted has left child
        ch=p->Left_child;
    else                  // node to be deleted has right child or no child
      ch=p->Right_child;

    if(par == NULL)  // if node to be deleted is root node
         root=ch;
    else if(p == par->Left_child) // node is left child of its parent
        par->Left_child =ch;
    else                    // node is right child of its parent
        par->Right_child = ch;
    free(p);
    return root;
}

struct node *searchNode(struct node *p,int x)
{
    if(p==NULL)
       return NULL;
    if(x < p->data)
       return searchNode(p->Left_child,x);
    if(x > p->data)
       return searchNode(p->Right_child,x);

    return p;

}

struct node *deleteNode_InorderPred(struct node *root,int x)  // To delete node from BST ( Way - Inorder Predecessor)
{
     struct node *par,*p,*ch,*s,*ps;
        p=root;
        par = NULL;
        while(p!=NULL)
        {
            if(x==p->data)
                break;
            par=p;
            if(x< p->data)
                p = p->Left_child;
            else
                p = p->Right_child;
        }
    if(p==NULL)
    {
        printf("%d not found \n",x);
        return root;
    }
   /*  CASE: 2 children */
    if(p->Left_child!=NULL && p->Right_child!=NULL) //Finding Inorder Predecessor and its parent
    {
        ps=p;
        s=p->Left_child;
        while(s->Right_child!=NULL)
        {
            ps=s;
            s=s->Right_child;
        }
        p->data=s->data;
        p=s;
        par=ps;
    }
     /*  CASE: 1 or no child */
    if(p->Left_child!=NULL)  // node to be deleted has left child
        ch=p->Left_child;
    else                  // node to be deleted has right child or no child
      ch=p->Right_child;

    if(par == NULL)  // if node to be deleted is root node
         root=ch;
    else if(p == par->Left_child) // node is left child of its parent
        par->Left_child =ch;
    else                    // node is right child of its parent
        par->Right_child = ch;
    free(p);
    return root;
}


int height_BT(struct node *p)   //To calculate height of BST
{
    int hL,hR;

    if(p==NULL)
       return 0;

    hL = height_BT(p->Left_child);
    hR = height_BT(p->Right_child);

    if(hR>hL)
        return hR;
    else
       return hL;
}

int Leaf_Count(struct node* root)  //To count no. of leaves in a BST
{
  if(root == NULL)
    return 0;
  if(root->Left_child == NULL && root->Right_child==NULL)
    return 1;
  else
    return(Leaf_Count(root->Left_child)+Leaf_Count(root->Right_child));
}

void Inorder_Without_Recursion(struct node *root)   //Inorder traversal Without Recursion
{ printf("\nInorder:");
  if(root == NULL)
    return;
  struct node *temp =root;
  initializeStk();


 while(!isEmpty() || temp !=NULL)
 {
     if(temp != NULL)
      {
         push(temp);
         temp = temp->Left_child;
      }
     else
     {
         temp = pop();
         printf("%d ",temp->data);
         temp = temp->Right_child;
     }
 }


  printf("\n");
}

// Inorder (Recursion)
void Inorder(struct node *p)

{
    if(p==NULL)
       return;
    Inorder(p->Left_child);
    printf("%d ",p->data);
    Inorder(p->Right_child);
}


void Preorder_Without_Recursion(struct node *root)   //Preorder traversal Without Recursion
{ printf("\nPreorder:");
struct node *temp = root;
if(root == NULL)
     return;
initializeStk();
push(root);
while(!isEmpty())
{
    temp = pop();
    printf("%d ",temp->data);
    if(temp->Right_child != NULL)
        push(temp->Right_child);
    if(temp->Left_child != NULL)
        push(temp->Left_child);
}
 printf("\n");
}

// Preorder (Recursion)
void Preorder(struct node *p)
{
    if(p==NULL)
       return;
    printf("%d ",p->data);
    Preorder(p->Left_child);
    Preorder(p->Right_child);
}

void Postorder_Without_Recursion(struct node *root)   //Postorder traversal Without Recursion
{
 printf("\nPostorder:");
 initializeStk();
 struct node *temp = root;
 struct node *prev = NULL;
 if(root == NULL)
    return;
 push(root);
 while(!isEmpty())
 {
     temp = Stacktop();
     if(prev == NULL || prev->Left_child == temp || prev->Right_child == temp)  //Moving down
     {
         if(temp->Left_child!=NULL)
            push(temp->Left_child);
        else if(temp->Right_child!=NULL)
            push(temp->Right_child);
        else if(temp->Left_child==NULL && temp->Right_child==NULL)
        {
            printf("%d ",temp->data);
            pop();
        }
     }
     if(prev == temp->Left_child) // Moving up from Left
     {
         if(temp->Right_child!=NULL)
         {
             push(temp->Right_child);
         }
         else
         {
             printf("%d ",temp->data);
             pop();
         }
     }
     if(prev==temp->Right_child)   // Moving up from right
     {
         printf("%d ",temp->data);
         pop();
     }
   prev = temp;
 }
 printf("\n");
}

// Postorder (Recursion)
void Postorder(struct node *p)

{
    if(p==NULL)
       return;
    Postorder(p->Left_child);
    Postorder(p->Right_child);
    printf("%d ",p->data);

}


int main()           //Main function
{
int a,k,val[100000];
struct node *p;
int n=0;
while(1)
{
  printf("1. To insert data in BST.\n");
  printf("2. To delete a node in BST.\n");
  printf("3. To display the number of leaves, the number of internal nodes, and the height of the tree.\n");
  printf("4. To display Inorder traversal of BST.\n");
  printf("5. To display Preorder traversal of BST.\n");
  printf("6. To display Postorder traversal of BST.\n");
  printf("7. Exit.\n");
  printf("\nEnter choice:");
  scanf("%d",&a);
if(a==7)
    break;
switch(a)
{

case 1: printf("\nEnter total no. of nodes followed by data of nodes(n x1 x2.....xn): ");
        scanf("%d",&k);
        if(k<=0)
        {
            printf("\nerror(Enter valid no. of node(s) to be inserted!!!!)\n\n");
            break;
        }
        for(int p=0;p<k;p++)
        {
           scanf("%d",&val[p]);
        }
        root = Insert_Node(root,val[0]);
        for(int i=1;i<k;i++)
        {
           Insert_Node(root,val[i]);
        }
        n+=k;
        printf("\nGiven nodes are inserted successfully.\n\n");
        break;

case 2: printf("\nEnter the node to be deleted:");
        scanf("%d",&k);
        p = searchNode(root,k);
        if(p == NULL)
          printf("\nerror\n\n");
        else if(n>0)
        {
        root = deleteNode_InorderPred(root,k);     //Using the way - Inorder Predecessor
        n--;
        printf("\n%d is deleted successfully!!\n\n",k);
        }
        break;

case 3: printf("\nNo. of leaves: %d",Leaf_Count(root));
        printf("\nNo. of Internal Nodes: %d",n-Leaf_Count(root));
        printf("\nHeight of BST: %d\n\n",height_BT(root));
        break;

case 4: Inorder_Without_Recursion(root);
        printf("\n");
        break;
case 5: Preorder_Without_Recursion(root);
        printf("\n");
        break;
case 6: Postorder_Without_Recursion(root);
        printf("\n");
        break;


default: printf("\nEnter Valid choice!!\n");

  }
}
  return 0;
}


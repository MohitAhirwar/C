#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* getNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// function to construct a BST from
// its level order traversal
struct Node *LevelOrder(struct Node *root , int data)
{
     if(root==NULL)
        {
        root = getNode(data);
        return root;
     }
     if(data <= root->data)
     root->left = LevelOrder(root->left, data);
     else
     root->right = LevelOrder(root->right, data);
     return root;
}

struct Node* constructBst(int arr[], int n)
{
    if(n==0)return NULL;
    struct Node *root =NULL;
    root = LevelOrder(root , arr[0]);
    for(int i=1;i<n;i++)
    LevelOrder(root , arr[i]);

    return root;
}
//Efficient Solution-1
//bool isBST(struct Node *root , int min , int max)
//{
//   if(root == NULL)            //If Tree is null its a BST
//          return true;

 //   return(root->data > min && root->data < max && isBST(root->left,min,root->data) && isBST(root->right,root->data,max));
//}



// Efficient Solution-2
// A binary Tree is a binary tree iff its INorder Traversal is sorted

int prev = INT_MIN;

bool isBST(struct Node *root)
{
       if(root==NULL)
          return true;
       if(isBST(root->left)==false)
          return false;
       if(root->data <= prev)
          return false;
       prev = root->data;
       return isBST(root->right);
}
int main()
{
  int min = INT_MIN;
  int max = INT_MAX;

  //Create BST
  int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *head = constructBst(arr, n);
// check it is bst or not
  if(isBST(head)==true)              //LOL we are constructing a BST and checking it is BST or not :)
         printf("Yes, it is a BST\n");
  else
        printf("Not a BST\n");

}
 /*BST:-
        7
       / \
      4   12
     / \  /
    3  6 8
   /  /   \
  1   5   10 */

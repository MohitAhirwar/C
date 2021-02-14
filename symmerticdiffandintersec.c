5#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 100003


int hash(int key)
{
    int r = (key) % TABLE_SIZE;
    if (r < 0)
        return (r + TABLE_SIZE);
    else
        return (r);
}

void insert(int *arr,int key)
{
    int index = hash(key);
    while(arr[index])
    {
        index =(index+1)%TABLE_SIZE;
    }
    arr[index] = key;

}

void intersection(int* a, int n1, int* b, int n2){
    int D[10000];
    int h1[10000]={0},h2[10000]={0};  // h1 is Hash1 and h2 is Hash2
    int k=0,i;
    for(i=0;i<n1;i++)
        insert(h1,a[i]++);

    for(i=0;i<n2;i++)
        insert(h2,b[i]++);

    for(i=0;i<10000;i++)
    if((h1[i]>=1 && h2[i]>=1))
    {
    D[k]=i;
    k++;
    }
    printf("\nIntersection of array1 and array2 is D: ");
     for(int i=0;i<k;i++)
      printf("%d ",D[i]);

      printf("\n");
}

int search(int *keys, int key)
{
    int index = hash(key);
    while (keys[index])
     {
        if (keys[index] == key)
        {
            return keys[index];
        }
        index = (index + 1)%TABLE_SIZE;
    }
    return 0;
}

void Symmetric_Diff(int a[],int n1,int b[], int n2)
{
int C[10000],d[10000],e[10000],p=0;
printf("\nSymmetic Difference of array1 and array2 is C: ");

for(int i=0;i<n1;i++)
 {
   insert(d,a[i]);
 }

for(int i=0;i<n2;i++)
 {
   insert(e,b[i]);
 }

for(int i=0;i<n1;i++)
{
     int x = a[i];
     int y = search(e,a[i]);

     if(x==y&& x!=search(C,a[i]))
        printf("");
     else
    {
        printf("%d ",a[i]);
        insert(C,a[i]);
    }
}

for(int i=0;i<n2;i++)
 {
     int x = b[i];
     int y = search(d,b[i]);

     if(x==y&& x!=search(C,a[i]))
        printf("");
     else
    {
        printf("%d ",b[i]);
        insert(C,b[i]);
    }
 }
 printf("\n");
}


int main()
{
  int A[100000],B[100000];
printf("Enter array1 in the form N,x1,x2,x3...,xN :\n");
    int n1;
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
        scanf(",%d",&A[i]);
printf("\nEnter array2 in the form N,x1,x2,x3...,xN: \n");
    int n2;
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
        scanf(",%d",&B[i]);
    Symmetric_Diff(A,n1,B,n2);
    intersection(A,n1,B,n2);
    return 0;
}

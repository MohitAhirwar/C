#include<stdio.h>
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

void insert(int *a, int *b, int key, int value)
{
    int index = hash(key);
    while (b[index]) {
        index = (index + 1) % TABLE_SIZE;
    }
    a[index] = key;
    b[index] = value;
}

int search(int *a, int *b, int key)
{
    int index = hash(key);
    while (b[index]) {
        if (a[index] == key) {
            return b[index];
        }
        index = (index + 1)%TABLE_SIZE;
    }
    return 0;
}

void Two_Sum(int* a, int n, int val)
{
    int keys[TABLE_SIZE],flag=0;
    int values[TABLE_SIZE] ={0};
    for (int i = 0; i < n; i++)
    {
        int comp = val - a[i];
        int value = search(keys, values, comp);
        if (value)
        {   flag = 1;
            int *pairs = (int *)malloc(sizeof(int)*2);
            pairs[0] = value-1;
            pairs[1] = i;
           printf("\nPair whose sum is %d : (%d,%d)",val,a[pairs[0]],a[pairs[1]]);
        }
        insert(keys, values,a[i], i+1);
    }

   if(flag ==0)
      printf("\nNot found\n");
}

int main()
{
    int A[100000],k;
    int n1;
    printf("Enter array in the form N,x1,x2,x3...,xN :\n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
        scanf(",%d",&A[i]);
    printf("Enter value of k :\n");
    scanf("%d",&k);
    Two_Sum(A,n1,k);
}

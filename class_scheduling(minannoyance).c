#include<stdio.h>
#include<stdlib.h>

struct Classes
{   int id;   // Class no.
    int s_t;  // start time
    int f_t;  // finish time
    int time;  // time duration
    int deadline; // deadline
 };

int max(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}

void merge_sort(struct Classes a[], int l, int h)
{
    int mid = 0;
    if(l == h)
    {
        return;
    }
    else
    {
        mid = (l+h)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}

void merge(struct Classes a[], int low, int mid, int high)
{
    int i;
    int l_index = low;
    int r_index = mid + 1;
    int index = low;
    struct Classes tmp[10];

    while(l_index <= mid && r_index <= high)
    {
        if(a[l_index].deadline <= a[r_index].deadline)
        {
            tmp[index++] = a[l_index++];
        }
        else
        {
            tmp[index++] = a[r_index++];
        }
    }

    if(l_index == mid + 1)
    {
        while(r_index <= high)
        {
            tmp[index++] = a[r_index++];
        }
    }
    else
    {
        while(l_index <= mid)
        {
            tmp[index++] = a[l_index++];
        }
    }
    for(i = low; i <= high; i++)
    {
        a[i] = tmp[i];
    }
}

int main()
{   int n;
    printf("Enter value of N and then enter time duration and deadlines for each cases:\n");
    scanf("%d",&n);
    struct Classes r[n];
    int t=0;
    for (int i=0;i<n;i++)
       {
        scanf("\n%d %d",&(r[i].time), &(r[i].deadline));
       }
    for (int i=0;i<n;i++)
    {
        r[i].id = i+1;
    }

    merge_sort(r,0,n-1);   // To sort the structure on the basis of deadlines

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(r[i].deadline == r[j].deadline)
            {
                if(r[i].time > r[j].time)
                {
                    r[i].time = r[i].time - r[j].time;    //Just to swap
                    r[j].time =r[i].time + r[j].time;
                    r[i].time = r[j].time - r[i].time;

                    r[i].id = r[i].id - r[j].id;            //Just to swap
                    r[j].id = r[i].id + r[j].id;
                    r[i].id = r[j].id - r[i].id;
                }
            }
    }
    for (int i=0;i<n;i++)
    {
        r[i].s_t = t;
        r[i].f_t = t + r[i].time;
        t = t + r[i].time;
    }

    // Print the start and finish time
    //printf("\nStart and Finish time of classes :\n\n");
   // for (int i = 0; i < n; i++) {
    //    printf("Class %d : Start time = %d, Finish time = %d \n",r[i].id,r[i].s_t, r[i].f_t);
   // }

    printf("\nOrder of Classes : ");
    for (int i = 0; i < n; i++)
    {  if(i!=n-1)
        printf("%d,",r[i].id);
       else
        printf("%d",r[i].id);
    }

  int total_annoyance = 0;
  for (int i = 0; i < n; i++)
  {
    total_annoyance += max( r[i].f_t - r[i].deadline ,0);
  }
    // Print the minimized total annoyance
    printf("\nTotal Annoyance : %d \n",total_annoyance);
    return 0;
}

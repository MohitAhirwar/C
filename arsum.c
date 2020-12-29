// Hackerrank Simple array sum

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int ar[1000],n,sum=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    { scanf("%d",&ar[i]);
    }
    for (int i=0;i<n;i++)
    {
        sum+=ar[i];
    }
    printf("%d",sum);
    return 0;
}

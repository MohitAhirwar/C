//Hackerrank Sum and difference

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

 
int main()
{
	int a,b,c,d;
    float p,q,r,s;
    scanf("%d %d\n",&a,&b);
    scanf("%f %f",&r,&s);
    c=a+b;
    d=a-b;
    p=r+s;
    q=r-s;
    printf("%d %d\n",c,d);
    printf("%.1f %.1f",p,q);
    return 0;
}

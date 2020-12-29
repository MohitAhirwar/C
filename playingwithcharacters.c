//Hackerrank Playing with characters

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 100
int main() 
{

    char ch;
    scanf("%c",&ch);
    printf("%c\n", ch);  
    char s[MAX_LEN],p[MAX_LEN];
    scanf("%s\n",s);
    printf("%s",s);
    printf("\n");
    scanf("%[^\n]%*c",p);
    printf(p);
     
    return 0;
}

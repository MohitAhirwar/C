#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
typedef long long ll;
#define MAXN 3002
ll dp[MAXN][MAXN];
ll steps[MAXN][MAXN];
bool vis[MAXN][MAXN];
int A[MAXN],N;
ll sum=0;
ll solve(int i,int j){
	if(vis[i][j]) return dp[i][j];
	vis[i][j] = 1;
	if(i == j){
      steps[i][j]=1;
      return dp[i][j] = A[i];
   }
   int m=A[i] - solve(i+1,j);
   int n=A[j] - solve(i,j-1);
   if(m>=n){
      steps[i][j]=1;
      return dp[i][j]=m;
   }else{
      steps[i][j]=-1;
      return dp[i][j]=n;
   }
}
int main(){

	scanf("%d",&N);
   if(N==0){
       printf("Maximum possible sum is %d \n",0);
       printf("Steps : ");
       return 0;
    }
	for(int i = 1;i<=N;i++){
		scanf("%d",&A[i]);
      sum+=A[i];
	}
   printf("Maximum possible sum is %d \n",(solve(1,N)+sum)/2);
   int i=1,j=N;
   int turn=1;
   printf("Steps : ");
   while (i<=j)
   {
      if(turn){
         if(steps[i][j]==-1){
           printf("%d ",A[j]);
            j--;
         }else{
            printf("%d ",A[i]);
            i++;
         }
      }else{
         if(steps[i][j]==-1){
            j--;
         }else{
            i++;
         }
      }
      turn^=1;
   }
   printf("\n");
	return 0;
}

#include<iostream>
using namespace std;
/* Recursive Solution
Time Complexity: O(2^n)
int knapsack(int v[],int w[],int n,int c)
{
  if(n==0 || c==0)
    return 0;
  if(w[n-1]>c)
    return knapsack(v,w,n-1,c);
  return max(v[n-1]+knapsack(v,w,n-1,c-w[n-1]),knapsack(v,w,n-1,c));
}*/
// Dynamic Programming Solution
// Time Complexity: O(n*c)
int knapsack(int v[],int w[],int n,int c)
{
  int dp[n+1][c+1] {};
  int i,j;
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=c;j++)
    {
      if(i==0 || j==0)
        dp[i][j]=0;
      else if(w[i-1]<=c)
        dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][c];
}
int main()
{
  int v[] = {60,100,120,300};
  int w[] = {10,20,40,20};
  int c = 60;
  int ans = knapsack(v,w,4,c);
  cout<<ans<<endl;
}

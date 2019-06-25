#include<iostream>
using namespace std;
/* Recursive Solution
Time Complexity: NP-Complete
int subset(int set[],int n,int sum)
{
  if(sum==0)
    return 1;
  if(n<0)
    return 0;
  return subset(set,n-1,sum-set[n-1]) || subset(set,n-1,sum);
}
*/
// Dynamic Programming
int subset(int set[],int n,int sum)
{
  int dp[n+1][sum+1];
  int i,j;
  //Sum = 0, true
  for(i=0;i<=n;i++)
    dp[i][0] = 1;
  //Sum!=0 and set = 0
  for(j=1;j<=sum;j++)
    dp[0][j] = 0;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=sum;j++)
    {
      if(set[i-1]>j)
        dp[i][j] = dp[i-1][j];
      if(set[i-1] <= j)
        dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
    }
  }
  /*To print the dp table
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=sum;j++)
    {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }*/
  return dp[n][sum];
}
int main()
{
  int n,sum;
  cout<<"Enter the size of the set:";
  cin>>n;
  int set[n];
  cout<<"Enter the elements of the set:";
  for(int i=0;i<n;i++)
    cin>>set[i];
  cout<<"Enter the sum:";
  cin>>sum;
  int ans = subset(set,n,sum);
  cout<<ans<<endl;
}

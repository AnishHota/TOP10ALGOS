// Longest Path in a matrix, increasing order with a difference of  1
//The path should either go up,down,left or right
#include<iostream>
using namespace std;
const int n = 3;
int find(int arr[n][n],int dp[n][n],int i,int j)
{
  //Base Case
  if(i<0 || j<0 || i>=n || j>=n)
    return 0;

  if(dp[i][j]!=0)
    return dp[i][j];

  if(i>0 && (arr[i][j]+1==arr[i-1][j]))
    return dp[i][j] = 1+find(arr,dp,i-1,j);
  if(j>0 && (arr[i][j]+1==arr[i][j-1]))
    return dp[i][j] = 1+find(arr,dp,i,j-1);
  if(i<n-1 && (arr[i][j]+1==arr[i+1][j]))
    return dp[i][j] = 1+find(arr,dp,i+1,j);
  if(j<n-1 && (arr[i][j]+1==arr[i][j+1]))
    return dp[i][j] = 1+find(arr,dp,i,j+1);

  return dp[i][j]=1;
}
int findMax(int arr[n][n])
{
  int dp[n][n] {};
  int i,j,result = 0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(dp[i][j]==0)
        dp[i][j] = find(arr,dp,i,j);
      result = max(result,dp[i][j]);
    }
  }
  return result;
}
int main()
{
  int arr[n][n];
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      cin>>arr[i][j];
  int ans = findMax(arr);
  cout<<ans<<endl;
  return 0;
}

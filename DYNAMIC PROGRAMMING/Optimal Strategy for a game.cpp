#include<iostream>
using namespace std;
int mv(int arr[],int n)
{
  int i,j,k;
  int x,y,z;
  int dp[n][n];
  for(k=0;k<n;k++)
  {
    for(i=0,j=k;j<n;i++,j++)
    {
      if(i+2<=j)
        x = dp[i+2][j];
      else
        x = 0;
      if(i+1<=j-1)
        y = dp[i+1][j-1];
      else
        y = 0;
      if(i<=j-2)
        z = dp[i][j-2];
      else
        z = 0;
      dp[i][j] = max(arr[i]+min(x,y),arr[j]+min(y,z));
    }
  }
  return dp[0][n-1];
}
int main()
{
  int arr[]= {20, 30, 2, 2, 2, 10};
  int n = sizeof(arr)/sizeof(arr[0]);
  int ans = mv(arr,n);
  cout<<ans<<endl;
  return 0;
}

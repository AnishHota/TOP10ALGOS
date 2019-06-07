#include<iostream>
using namespace std;
string x,y;
int lcs(int m,int n)
{
  int arr[m+1][n+1];
  int i,j;
  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
    {
      if(i==0 || j==0)
        arr[i][j]=0;
      else if(x[i-1]==y[j-1])
        arr[i][j] = 1+arr[i-1][j-1];
      else
        arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
    }
  }
  i=m;
  j=n;
  string lc = "";
  while(i>0 && j>0)
  {
    if(x[i-1]==y[j-1])
    {
      lc+=x[i-1];
      i--;j--;
    }
    if(arr[i-1][j]>arr[i][j-1])
      i--;
    else
      j--;
  }
  for(i=lc.length()-1;i>=0;i--)
  {
    cout<<lc[i]<<" ";
  }
  cout<<endl;
  return arr[m][n];
}
int main()
{
  cin>>x>>y;
  int ans = lcs(x.length(),y.length());
  cout<<ans<<endl;
  return 0;
}


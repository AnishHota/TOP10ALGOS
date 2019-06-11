#include<iostream>
using namespace std;
string a,b;
int editdistance(int m,int n)
{
  int arr[m+1][n+1];
  int i,j;
  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
    {
      if(i==0)
        arr[i][j]=j;
      else if(j==0)
        arr[i][j]=i;
      else if(a[i-1]!=b[j-1])
      {
        arr[i][j] = 1+min(arr[i-1][j-1],min(arr[i][j-1],arr[i-1][j]));
      }
      else
        arr[i][j] = arr[i-1][j-1];
    }
  }
  /*To Display the 2D matrix
  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
      cout<<arr[i][j]<<" ";
    cout<<endl;
  }*/
  return arr[m][n];
}
int main()
{
  cin>>a>>b;
  int ops = editdistance(a.length(),b.length());
  cout<<ops<<endl;
  return 0;
}

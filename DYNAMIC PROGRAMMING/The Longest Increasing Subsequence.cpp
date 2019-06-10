#include<iostream>
#include<vector>
using namespace std;
int bs(vector<int> li,int x)
{
  int i=0;
  int j = li.size()-1;
  while(i<j)
  {
    int m = i+(j-i)/2;
    if(li[m]>=x)
      j=m;
    else
      i=m+1;
  }
  return j;
}
int lis(int arr[],int n)
{
  vector<int> li;
  int i,j;
  int index=0;
  li.push_back(arr[0]);
  for(i=1;i<n;i++)
  {
    if(arr[i]>li[index])
    {
      li.push_back(arr[i]);
      index++;
    }
    else
    {
      int pos = bs(li,arr[i]);
      if(pos!=-1)
        li[pos] = arr[i];
    }
  }
  return li.size();
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  int i;
  for(i=0;i<n;i++)
    cin>>arr[i];
  int ans = lis(arr,n);
  cout<<ans<<endl;
}

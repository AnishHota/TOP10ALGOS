// CONVERT ARRAY INTO ZIG-ZAG FASHION
// a<b>c<d>e<f
#include<iostream>
using namespace std;
void zigzag(int arr[],int n)
{
  int i;
  bool flag = true;
  for(i=0;i<n-1;i++)
  {
    // flag=0 means <
    if(flag)
    {
      if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
      flag=false;
    }
    else
    {
      if(arr[i]<arr[i+1])
        swap(arr[i],arr[i+1]);
      flag=true;
    }
  }
}
int main()
{
  int i;
  int arr[] = {4,3,7,8,6,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  zigzag(arr,n);
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}

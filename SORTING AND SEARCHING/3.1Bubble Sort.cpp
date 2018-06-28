// BUBBLE SORT
#include<iostream>
using namespace std;
void bubblesort(int arr[],int n)
{
  int i,j;
  for(i=n-1;i>=0;i--)
  {
    for(j=0;j<i;j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
      }
    }
  }
}
int main()
{
  int i;
  int arr[] = {1,6,3,2,7,4};
  int n = sizeof(arr)/sizeof(arr[0]);
  bubblesort(arr,n);
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}

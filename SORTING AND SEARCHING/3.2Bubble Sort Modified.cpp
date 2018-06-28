// BUBBLE SORT MODIFIED
#include<iostream>
using namespace std;
void bubblesortmodified(int arr[],int n)
{
  int i,j,swapped=1;
  for(i=n-1;i>=0 && swapped;i--)
  {
    swapped = 0;
    for(j=0;j<i;j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
        swapped = 1;
      }
    }
  }
}
int main()
{
  int i;
  int arr[] = {1,6,3,2,7,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  bubblesortmodified(arr,n);
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}
